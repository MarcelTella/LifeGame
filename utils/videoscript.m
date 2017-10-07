% Take the LifeGame output file and turns it into a video.
% videoscript(filename, 100, 100);
function videoscript(filename, nRows, nCols)
    images = loadMatrices(filename, nRows, nCols);
    createVideo('GameOfLife.avi', images);