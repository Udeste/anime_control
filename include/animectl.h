#pragma once

#include <hidapi/hidapi.h>

class AnimeCtl {

  public:
    AnimeCtl(unsigned short vendor_id,
             unsigned short product_id);

    void init();
    void init_device();

    void enable_matrix(bool enabled);
    void enable_builtin_anim(bool enabled);

    void set_brightness(int brightness);

    void close();
    void flush();
  private:
    hid_device* hid_handle;
    unsigned short vendor_id;
    unsigned short product_id;

    void init_hid_lib();
    void open_hid_device();
    void write_packets(unsigned char* pkts, size_t size);
};

