function [] = show_freq(signal, l, Fs, title_txt)
    f = (-l/2:l/2-1)*(Fs/l);
    f_vals = fftshift(fft(signal)/l);
    
    plot(f, abs(f_vals));
    grid();
    xlabel("Frequency (Hz)");
    ylabel("Amplitude");
    title(title_txt);
end 