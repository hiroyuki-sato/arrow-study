require 'test_helper'

class SchemaTest < Test::Unit::TestCase
  # Integers
  #   :uint8
  #   :uint16
  #   :uint32
  #   :uint64
  #
  #   :int16
  #   :int32
  #   :int64
  #   :int8
  # Float & Double
  #   :float
  #   :floating_point
  #   :half_float
  #   :double
  # Time
  #   :time
  #   :time32
  #   :time64
  #
  # :binary
  # :boolean
  # :date32
  # :date64
  # :day_time_interval
  # :decimal
  # :decimal128
  # :decimal256
  # :dense_union
  # :dictionary
  # :extension
  # :fixed_size_binary
  # :fixed_width
  # :integer
  # :interval
  # :large_binary
  # :large_list
  # :large_string
  # :list
  # :map
  # :month_day_nano_interval
  # :month_interval
  # :null
  # :numeric
  # :run_end_encoded
  # :sparse_union
  # :string
  # :struct
  # :temporal
  # :timestamp
  # :union
  def test_it_does_something_useful
    # Unsigned Integers
    Arrow::Field.new("uint8",  :uint8)
    Arrow::Field.new("uint16", :uint16)
    Arrow::Field.new("uint32", :uint32)
    Arrow::Field.new("uint64", :uint64)
    assert_raise(ArgumentError) do 
      Arrow::Field.new("uint128", :uint128)
    end

    # Integers
    Arrow::Field.new("int8",  :int8)
    Arrow::Field.new("int16", :int16)
    Arrow::Field.new("int32", :int32)
    Arrow::Field.new("int64", :int64)
    assert_raise(ArgumentError) do 
      Arrow::Field.new("int128", :int128)
    end

    # Floats
    f = Arrow::Field.new("float",  :float)
    #raise Error
    #Arrow::Field.new("floating_point", :floating_point)
    Arrow::Field.new("half_float", :half_float)
    Arrow::Field.new("double", :double)

    Arrow::Field.new("time", :time222)
    Arrow::Field.new("time", :time)
    #Arrow::Field.new("time32", :time32)
    #Arrow::Field.new("time64", :time64)

    assert true
  end
  def test_hogehoge
#    types = [:run_end_encoded, :sparse_union, :string, :struct, :date32, :date64, :day_time_interval, :temporal, :time32, :decimal128, :decimal256, :decimal, :time64, :timestamp, :dense_union, :dictionary, :time, :double, :uint16, :uint32, :uint64, :uint8, :union, :extension, :fixed_size_binary, :fixed_width, :float, :floating_point, :half_float, :int16, :int32, :int64, :int8, :integer, :interval, :large_binary, :large_list, :large_string, :list, :map, :month_day_nano_interval, :month_interval, :null, :numeric, :binary, :boolean]
    types = [:run_end_encoded, :sparse_union, :string, :struct, :date32, :date64, :day_time_interval, :temporal, :time32, :decimal128, :decimal256, :decimal, :time64, :timestamp, :dense_union, :dictionary, :time, :double, :uint16, :uint32, :uint64, :uint8, :union, :fixed_size_binary, :fixed_width, :float, :floating_point, :half_float, :int16, :int32, :int64, :int8, :integer, :interval, :large_binary, :large_list, :large_string, :list, :map, :month_day_nano_interval, :month_interval, :null, :numeric, :binary, :boolean]
    types.each do |t|
      begin
        puts "*** #{t} ***"
        t = Arrow::Field.new(t.to_s,t)
      rescue
        puts "ERROR"
      end
    end
  end
end


