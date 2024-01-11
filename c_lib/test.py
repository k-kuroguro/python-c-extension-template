def test_add():
    from c_lib import add

    assert add(1, 2) == 3
    assert add(4, 0) == 4
    assert add(2, -1) == 1
