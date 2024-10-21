require 'test_helper'

class TimeTest < Test::Unit::TestCase

  def test_units
    # No hour, minute
    assert_equal("00:00:01",Arrow::Time.new(:second,1).to_s)
    assert_equal("00:00:00.001",Arrow::Time.new(:milli,1).to_s)
    assert_equal("00:00:00.000001",Arrow::Time.new(:micro,1).to_s)
    assert_equal("00:00:00.000000001",Arrow::Time.new(:nano,1).to_s)
  end
end

