#include "../include/animectl.h"
#include <cstdint>
#include <iostream>
#include <cstring>

AnimeCtl::AnimeCtl(unsigned short vendor_id,
                   unsigned short product_id) :
  vendor_id   (vendor_id),
  product_id  (product_id)
{}

void AnimeCtl::init() {
  this->init_hid_lib();
  this->open_hid_device();
}

// Initialize the HID library
void AnimeCtl::init_hid_lib() {
  if (hid_init() != 0) {
    throw std::runtime_error("Failed to initialize HIDAPI");
  }
}

//Open the device
void AnimeCtl::open_hid_device() {
  this->hid_handle = hid_open(this->vendor_id, this->product_id, nullptr);
  if (!this->hid_handle) {
    throw std::runtime_error("Cannot open device. Is it connected? Do you have the right permissions to access it?");
  }
  std::cout << "Device opened successfully!\n";
}

void AnimeCtl::init_device() {
  unsigned char str[15] = "ASUS Tech.Inc.";

  this->write_packets(str, sizeof(str));
}

void AnimeCtl::enable_matrix(bool enabled = true) {
  uint8_t buf[] = {
    0xc3,
    0x01,
    static_cast<uint8_t>(enabled ? 0x00 : 0x80)
  };

  this->write_packets(buf, sizeof(buf));
}

void AnimeCtl::set_brightness(int brightness = 3) {
  uint8_t buf[] = {
    0xc0,
    0x04,
    static_cast<uint8_t>(brightness)
  };

  this->write_packets(buf, sizeof(buf));
}

void AnimeCtl::enable_builtin_anim(bool enabled = true) {
  uint8_t buf[] = {
    0xc4,
    0x01,
    static_cast<uint8_t>(enabled ? 0x00 : 0x80)
  };

  this->write_packets(buf, sizeof(buf));
}

void AnimeCtl::flush() {
  uint8_t buf[] = {
    0xc0,
    0x03
  };

  this->write_packets(buf, sizeof(buf));
}


void AnimeCtl::write_packets(uint8_t* pkts, size_t size) {

  uint8_t full_pkt[64] = {0}; // Full packet size is 64 bytes for Anime Matrix
  full_pkt[0] = 0x5e; // DEV page ID
  std::memcpy(full_pkt + 1, pkts, size);

  int res = hid_write(this->hid_handle, full_pkt, sizeof(full_pkt));
  if (res < 0) {
    throw std::runtime_error("Failed to write to device");
  } else {
    std::cout << "Sent " << pkts << " bytes to device"  << std::endl;
  }
}

void AnimeCtl::close() {
  hid_close(this->hid_handle);

  hid_exit();
}
