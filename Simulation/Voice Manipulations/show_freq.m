function [] = show_freq(signal, l, Fs, title_txt)
    f = (-l/2:l/2-1)*(Fs/l);
    f_vals = fft(signal)/l;
    
    f_edit = [flip(f_vals(1:2500)) ,f_vals(1:2500)];
    
    plot(f, abs(f_vals));
    grid();
    xlabel("Frequency (Hz)");
    ylabel("Amplitude");
    title(title_txt);
end 