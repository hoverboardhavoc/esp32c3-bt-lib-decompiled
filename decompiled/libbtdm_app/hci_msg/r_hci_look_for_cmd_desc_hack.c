/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> hci_msg.o -> r_hci_look_for_cmd_desc_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ushort * r_hci_look_for_cmd_desc_hack(uint param_1)

{
  ushort *puVar1;
  ushort *puVar2;
  short sVar3;
  ushort *puVar4;
  
  puVar1 = (ushort *)r_hci_look_for_cmd_desc();
  puVar2 = puVar1;
  if (((puVar1 == (ushort *)0x0) && (0xfc80 < param_1)) && (esp_vendor_cmd_ext != (undefined *)0x0))
  {
    sVar3 = 0;
    for (puVar4 = (ushort *)esp_vendor_cmd_ext;
        (puVar2 = puVar1, DAT_00010074 != sVar3 &&
        (puVar2 = puVar4, (param_1 & 0x3ff) != (*puVar4 & 0x3ff))); puVar4 = puVar4 + 6) {
      sVar3 = sVar3 + 1;
    }
  }
  return puVar2;
}

