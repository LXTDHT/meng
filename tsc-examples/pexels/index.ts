const PEXELS_API_KEY : string = 'QTF7k7XVbvM9t0rr8G3WFqXBmqdogDHZCFD5JrU2GAOQ6UIt0zjy5dvi';

async function fetchImages(searchTerm: string = '', perPage: number = 10) {
    const result = await fetch(`https://api.pexels.com/v1/search?query=${searchTerm}&per_page=${perPage}`, {
        headers: {
            Authorization: PEXELS_API_KEY
        }
    });
    const data = await result.json();
    return data;

    // const imagesContainer = document.querySelector('#images-container');
    // if (imagesContainer == null) {
    //     throw new Error('Could not find images-container element.');
    // }
    // for (const photo of data.photos) {
    //     const img = document.createElement('img');
    //     img.src = photo.src.medium;
    //     imagesContainer.append(img);
    // }
}
fetchImages('dogs', 5);
fetchImages('cats');
fetchImages();