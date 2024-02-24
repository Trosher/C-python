import ctypes
import time
import platform

if platform.system() == 'Windows':
    def monotonic():
        return ctypes.windll.kernel32.GetTickCount64() / 1000.0
elif platform.system() == 'Linux':
    def monotonic():
        class timespec(ctypes.Structure):
            _fields_ = [("tv_sec", ctypes.c_long), ("tv_nsec", ctypes.c_long)]
        libc = ctypes.CDLL("libc.so.6")
        ts = timespec()
        libc.clock_gettime(1, ctypes.byref(ts))
        return ts.tv_sec + ts.tv_nsec /1e9
elif platform.system() == 'Darwin':
    def monotonic():
        info = ctypes.c_uint64()
        ctypes.cdll.LoadLibrary('libSystem.dylib').mach_absolute_time(ctypes.byref(info))
        return info.value / 1e9

def main():
    print("my time: ",monotonic())
    print("lib time: ",time.monotonic())

if __name__ == "__main__":
    main()