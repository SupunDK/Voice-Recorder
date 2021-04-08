file = "africa-toto.wav";

[y, Fs] = audioread(file, [20*22050, 30*22050]);

figure;
show_freq_equaliser(y, length(y), Fs);