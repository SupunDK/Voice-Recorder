function [] = show_freq_equaliser(signal, l, Fs, title_txt)
    f = (-l/2:l/2-1)*(Fs/l);
    f_vals = fftshift(fft(signal)/l);
    
    plot(f, abs(f_vals));
    grid();
    xlabel("Frequency (Hz)");
    ylabel("Amplitude");
    xlim([-5000, 5000]);
    title(title_txt);
end 