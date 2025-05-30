const arrow = require('apache-arrow');
describe('Field', () => {
  it('Create Field', () => {
    const data = [10, 20, 30, 40, 50, 60];
    console.log(data);
    //console.log(arrow.Uint8);
    //const data2 = arrow.makeData(arrow.Uint8, [10, 20, 30, 40, 50]);
    const data2 = arrow.vectorFromArray(data, new arrow.Uint8);
    console.log(data2);

    //const field = new arrow.Vector(data);

    expect(data.length).toBe(6);
  });
});

