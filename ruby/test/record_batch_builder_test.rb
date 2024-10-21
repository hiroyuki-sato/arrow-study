require 'test_helper'

class RecordBatchBuilderTest < Test::Unit::TestCase

  def test_it_does_something_useful
    schema = [{ name: :c1, type: :uint8  },
              { name: :c2, type: :uint32 },
              { name: :c2, type: :uint64 }]

    data = [[1,2,3],[1,2,3],[1,2,3]]
    b = Arrow::RecordBatchBuilder.build(schema, data)
p b.class
p b.schema
             
    assert true
  end
end

