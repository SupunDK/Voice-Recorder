function [] = show_freq(signal, t, Fs)
    l = length(t);
    
    f = Fs*(0:l-1)/l;
    f_vals = fft(signal)/l;
    
    plot(f, abs(f_vals));
end 