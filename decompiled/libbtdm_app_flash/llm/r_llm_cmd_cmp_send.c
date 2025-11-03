/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llm.o -> r_llm_cmd_cmp_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_cmd_cmp_send(uint param_1,int param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)r_ke_msg_alloc(0x1101,0,param_1,1);
  if ((_sdk_cfg_priv_opts != 0) && (param_2 == 0xfe)) {
    param_2 = 0;
  }
  *puVar1 = (char)param_2;
  r_hci_send_2_host();
  if (param_2 != 0) {
    r_ble_log_internal_x1(0x806e00e8,param_2 << 0x10 | param_1);
    return;
  }
  return;
}

