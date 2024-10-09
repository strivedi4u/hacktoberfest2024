function useDebounce(cb, delay = 500) {
    let timerId;
    return (...args) => {
        clearTimeout(timerId);
        timerId = setTimeout(() => {
            cb(...args);
        }, delay)
    }
}

export default useDebounce;