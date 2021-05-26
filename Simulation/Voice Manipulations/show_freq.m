function [] = show_freq(signal, l, Fs, title_txt)
    f = (-l/2:l/2-1)*(Fs/l);
    f_vals = fft(signal)/l;
    
    f_edit = [flip(f_vals(1:2500)) ,f_vals(1:2500)];
    
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    plot(f, abs(f_vals));
=======
    plot(f, abs(f_edit));
>>>>>>> 475e5fff8f582ad36f87f7024429a81d02e039a6
=======
    plot(f, abs(f_edit));
>>>>>>> 475e5fff8f582ad36f87f7024429a81d02e039a6
=======
    plot(f, abs(f_edit));
>>>>>>> 475e5fff8f582ad36f87f7024429a81d02e039a6
    grid();
    xlabel("Frequency (Hz)");
    ylabel("Amplitude");
    title(title_txt);
end 