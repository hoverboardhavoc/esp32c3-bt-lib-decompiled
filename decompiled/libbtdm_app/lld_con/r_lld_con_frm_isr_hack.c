/*
 * Last changed at upstream commit 2a91d90e33b3b1104daf1bff898fe5bc3f814811
 * https://github.com/espressif/esp32c3-bt-lib/commit/2a91d90e33b3b1104daf1bff898fe5bc3f814811
 * Upstream date: 2022-09-07 12:18:28 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(2ee0168e)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_frm_isr_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_frm_isr_hack(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = lld_con_terminate_max_evt_update
                    ((int)(uint)*(ushort *)(*(int *)(&lld_con_env + param_1 * 4) + 0x84) >> 8 & 1);
  if (iVar1 == 0) {
    r_lld_con_frm_isr(param_1,param_2,param_3);
    return;
  }
  return;
}

