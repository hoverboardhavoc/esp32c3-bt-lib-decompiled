/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_dl_upd.o -> r_llc_hci_dl_upd_info_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_hci_dl_upd_info_send
               (undefined4 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,
               undefined2 param_5)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)r_ke_msg_alloc(0x1104,param_1,0x3e,0xc);
  *puVar1 = 7;
  *(short *)(puVar1 + 2) = (short)param_1;
  *(undefined2 *)(puVar1 + 8) = param_5;
  *(undefined2 *)(puVar1 + 10) = param_4;
  *(undefined2 *)(puVar1 + 4) = param_3;
  *(undefined2 *)(puVar1 + 6) = param_2;
  r_hci_send_2_host();
  return;
}

