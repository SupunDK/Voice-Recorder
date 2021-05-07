function [signal_out] = frequency_shifting(signal, t, F_shift)
    offset = cos(2*pi*F_shift*t);
    
    signal_out = signal .* (offset');
end