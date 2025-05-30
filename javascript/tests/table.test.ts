const arrow = require('apache-arrow');
describe('Field', () => {
  it('Create Table', () => {
    const table = arrow.makeTable({
      a: new Int8Array([1, 2, 3]),
      b: new Int16Array([4, 5, 6]),
    })

    const fields = table.schema.fields.map(field => field.name)
    expect(fields).toStrictEqual(["a","b"])
  });
});
