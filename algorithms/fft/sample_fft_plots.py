from scipy.fft import fft
import numpy as np
import matplotlib.pyplot as plt


def main():
    end = 5
    N = 10000
    Ts = end/N

    t = np.linspace(start=0, stop=end, num=N)
    y = np.sin(2*np.pi*t) + 2*np.cos(2*np.pi*3*t) + 0.5*np.sin(2*np.pi*5*t)
    xf = np.linspace(0, 1/(2*Ts), N//2)
    yf = fft(y, norm="ortho")

    plt.subplot(1, 2, 1)
    plt.grid()
    plt.title("Time-Domain Plot")
    plt.xlabel("Time $(s)$")
    plt.ylabel("Amplitude $y(t)$")
    plt.plot(t, y, label="$y(t) = \sin(2\pi\cdot t) + 2\cdot\cos(2\pi\cdot 3t) + 0.5\cdot\sin(2\pi\cdot 5t)$")
    plt.legend()

    plt.subplot(1, 2, 2)
    plt.grid()
    plt.title("Amplitude Spectrum Plot")
    plt.xlabel("Frequency $(Hz)$")
    plt.ylabel("Amplitude $|Y(f)|$")
    plt.plot(xf, 2/N*np.abs(yf[:N//2]))
    plt.xlim(0, 6)
    plt.show()


if __name__ == '__main__':
    main()
