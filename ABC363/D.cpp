def gen_nth_pal(N):
    if N == 1:
        return "0"

    cnt = 1
    length = 1

    while True:
        if length == 1:
            pal_len = 9
        elif length % 2 == 0:
            pal_len = 9 * 10 ** (length // 2 - 1)
        else:
            pal_len = 9 * 10 ** (length // 2)

        if cnt + pal_len >= N:
            break

        cnt += pal_len
        length += 1

    half_len = (length + 1) // 2
    offset = N - cnt - 1
    fh = 10 ** (half_len - 1) + offset

    fh_str = str(fh)
    pal = fh_str

    if length % 2 == 1:
        pal += fh_str[:-1][::-1]
    else:
        pal += fh_str[::-1]

    return pal

N = int(input())

print(gen_nth_pal(N))