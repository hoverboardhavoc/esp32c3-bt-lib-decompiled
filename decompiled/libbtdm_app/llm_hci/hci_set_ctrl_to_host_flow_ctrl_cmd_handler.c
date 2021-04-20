/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> llm_hci.o -> hci_set_ctrl_to_host_flow_ctrl_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_set_ctrl_to_host_flow_ctrl_cmd_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  undefined4 uVar2;
  
  bVar1 = *param_1;
  uVar2 = 0x12;
  if (bVar1 < 4) {
    uVar2 = (**(code **)(_r_ip_funcs_p + 0xb0))
                      (bVar1 == 1 || bVar1 == 3,0x12,*(code **)(_r_ip_funcs_p + 0xb0));
  }
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,uVar2,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

