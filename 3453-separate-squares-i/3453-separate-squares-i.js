var separateSquares = function(squares) {
    let low = Infinity, high = -Infinity;

    for (let [x, y, l] of squares) {
        low = Math.min(low, y);
        high = Math.max(high, y + l);
    }

    function areaDiff(h) {
        let below = 0, above = 0;

        for (let [x, y, l] of squares) {
            let bottom = y;
            let top = y + l;
            let area = l * l;

            if (h >= top) {
                below += area;
            } else if (h <= bottom) {
                above += area;
            } else {
                below += (h - bottom) * l;
                above += (top - h) * l;
            }
        }
        return below - above;
    }

    for (let i = 0; i < 60; i++) { // enough for 1e-5 precision
        let mid = (low + high) / 2;
        if (areaDiff(mid) < 0) {
            low = mid;
        } else {
            high = mid;
        }
    }

    return low;
};
