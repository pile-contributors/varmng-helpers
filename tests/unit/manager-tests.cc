#include <gtest/gtest.h>
/*
class TestColumnCtors : public ::testing::Test {

public:

    TestColumnCtors () : inst_(NULL) {}

    virtual ~TestColumnCtors () {}

    void SetUp(){
        //inst_ = new DbStruct();
    }
    void TearDown(){
        //delete inst_;
    }
    DbStruct * inst_;
};
*/

/*
TEST(TestColumnCtors, default_constructor) {
    DbColumn testee;
    EXPECT_FALSE(testee.isVirtual ());
    EXPECT_TRUE(testee.columnName ().isEmpty());
    EXPECT_TRUE(testee.columnLabel ().isEmpty());
    EXPECT_EQ(testee.columnId (), -1);
    EXPECT_EQ(testee.columnRealId (), -1);
    EXPECT_EQ(testee.columnLength (), -1);
    EXPECT_EQ(testee.columnType (), DbDataType::DTY_INVALID);
    EXPECT_TRUE(testee.allowNulls());
    EXPECT_FALSE(testee.readOnly());
}

TEST(TestColumnCtors, simple_constructor_only_required) {
    QString col_name ("col1");
    int col_id = 0;
    DbColumn testee (col_name, DbDataType::DTY_TEXT, col_id);

    EXPECT_FALSE(testee.isVirtual ());
    EXPECT_FALSE(testee.columnName ().isEmpty());
    EXPECT_FALSE(testee.columnLabel ().isEmpty());
    EXPECT_EQ(testee.columnName (), col_name);
    EXPECT_EQ(testee.columnLabel (), col_name);
    EXPECT_EQ(testee.columnId (), col_id);
    EXPECT_EQ(testee.columnRealId (), col_id);
    EXPECT_EQ(testee.columnLength (), dbstruct::UNDEFINED);
    EXPECT_EQ(testee.columnType (), DbDataType::DTY_TEXT);
    EXPECT_TRUE(testee.allowNulls());
    EXPECT_FALSE(testee.readOnly());
}

TEST(TestColumnCtors, simple_constructor_label) {
    QString col_name ("col1");
    QString col_label ("First Column");
    int col_id = 0;
    DbColumn testee (col_name, DbDataType::DTY_TEXT, col_id, col_label);

    EXPECT_FALSE(testee.isVirtual ());
    EXPECT_FALSE(testee.columnName ().isEmpty());
    EXPECT_FALSE(testee.columnLabel ().isEmpty());
    EXPECT_EQ(testee.columnName (), col_name);
    EXPECT_EQ(testee.columnLabel (), col_label);
    EXPECT_EQ(testee.columnId (), col_id);
    EXPECT_EQ(testee.columnRealId (), col_id);
    EXPECT_EQ(testee.columnLength (), dbstruct::UNDEFINED);
    EXPECT_EQ(testee.columnType (), DbDataType::DTY_TEXT);
    EXPECT_TRUE(testee.allowNulls());
    EXPECT_FALSE(testee.readOnly());
}

TEST(TestColumnCtors, simple_constructor_real_col_id) {
    QString col_name ("col1");
    QString col_label ("First Column");
    int col_id = 44;
    int real_id = 43;
    DbColumn testee (col_name, DbDataType::DTY_TEXT,
                     col_id, col_label, real_id);

    EXPECT_FALSE(testee.isVirtual ());
    EXPECT_FALSE(testee.columnName ().isEmpty());
    EXPECT_FALSE(testee.columnLabel ().isEmpty());
    EXPECT_EQ(testee.columnName (), col_name);
    EXPECT_EQ(testee.columnLabel (), col_label);
    EXPECT_EQ(testee.columnId (), col_id);
    EXPECT_EQ(testee.columnRealId (), real_id);
    EXPECT_EQ(testee.columnLength (), dbstruct::UNDEFINED);
    EXPECT_EQ(testee.columnType (), DbDataType::DTY_TEXT);
    EXPECT_TRUE(testee.allowNulls());
    EXPECT_FALSE(testee.readOnly());
}

TEST(TestColumnCtors, simple_constructor_length) {
    QString col_name ("col1");
    QString col_label ("First Column");
    int col_id = 44;
    int length = 43;
    DbColumn testee (col_name, DbDataType::DTY_TEXT,
                     col_id, col_label, dbstruct::DEFAULT, length);

    EXPECT_FALSE(testee.isVirtual ());
    EXPECT_FALSE(testee.columnName ().isEmpty());
    EXPECT_FALSE(testee.columnLabel ().isEmpty());
    EXPECT_EQ(testee.columnName (), col_name);
    EXPECT_EQ(testee.columnLabel (), col_label);
    EXPECT_EQ(testee.columnId (), col_id);
    EXPECT_EQ(testee.columnRealId (), col_id);
    EXPECT_EQ(testee.columnLength (), length);
    EXPECT_EQ(testee.columnType (), DbDataType::DTY_TEXT);
    EXPECT_TRUE(testee.allowNulls());
    EXPECT_FALSE(testee.readOnly());
}

TEST(TestColumnCtors, simple_constructor_allow_nulls) {
    QString col_name ("col1");
    QString col_label ("First Column");
    int col_id = 44;
    DbColumn testee (col_name, DbDataType::DTY_TEXT,
                     col_id, col_label,
                     dbstruct::DEFAULT, dbstruct::UNDEFINED,
                     false);

    EXPECT_FALSE(testee.isVirtual ());
    EXPECT_FALSE(testee.columnName ().isEmpty());
    EXPECT_FALSE(testee.columnLabel ().isEmpty());
    EXPECT_EQ(testee.columnName (), col_name);
    EXPECT_EQ(testee.columnLabel (), col_label);
    EXPECT_EQ(testee.columnId (), col_id);
    EXPECT_EQ(testee.columnRealId (), col_id);
    EXPECT_EQ(testee.columnLength (), dbstruct::UNDEFINED);
    EXPECT_EQ(testee.columnType (), DbDataType::DTY_TEXT);
    EXPECT_FALSE(testee.allowNulls());
    EXPECT_FALSE(testee.readOnly());

    DbColumn testee2 (col_name, DbDataType::DTY_TEXT,
                      col_id, col_label,
                      dbstruct::DEFAULT, dbstruct::UNDEFINED,
                      true);
    EXPECT_TRUE(testee2.allowNulls());
}


TEST(TestColumnCtors, simple_constructor_readonly) {
    QString col_name ("col1");
    QString col_label ("First Column");
    int col_id = 44;
    DbColumn testee (col_name, DbDataType::DTY_TEXT,
                     col_id, col_label,
                     dbstruct::DEFAULT, dbstruct::UNDEFINED,
                     false, true);

    EXPECT_FALSE(testee.isVirtual ());
    EXPECT_FALSE(testee.columnName ().isEmpty());
    EXPECT_FALSE(testee.columnLabel ().isEmpty());
    EXPECT_EQ(testee.columnName (), col_name);
    EXPECT_EQ(testee.columnLabel (), col_label);
    EXPECT_EQ(testee.columnId (), col_id);
    EXPECT_EQ(testee.columnRealId (), col_id);
    EXPECT_EQ(testee.columnLength (), dbstruct::UNDEFINED);
    EXPECT_EQ(testee.columnType (), DbDataType::DTY_TEXT);
    EXPECT_FALSE(testee.allowNulls());
    EXPECT_TRUE(testee.readOnly());

    DbColumn testee2 (col_name, DbDataType::DTY_TEXT,
                      col_id, col_label,
                      dbstruct::DEFAULT, dbstruct::UNDEFINED,
                      false, false);
    EXPECT_FALSE(testee2.readOnly());
}
*/
