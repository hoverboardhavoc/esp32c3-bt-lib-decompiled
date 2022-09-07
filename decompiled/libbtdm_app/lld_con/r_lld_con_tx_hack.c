/*
 * Last changed at upstream commit 2a91d90e33b3b1104daf1bff898fe5bc3f814811
 * https://github.com/espressif/esp32c3-bt-lib/commit/2a91d90e33b3b1104daf1bff898fe5bc3f814811
 * Upstream date: 2022-09-07 12:18:28 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(2ee0168e)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_tx_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_tx_hack(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1 * 4;
  iVar2 = *(int *)(&lld_con_env + iVar1);
  r_lld_con_tx();
  if (((lld_con_term_info[iVar1] != '\0') && (lld_con_term_info[iVar1 + 2] == '\0')) &&
     (param_1 * 9 + (uint)*(byte *)(iVar2 + 0x90) == (uint)(byte)lld_con_term_info[iVar1 + 1])) {
    lld_con_term_info[iVar1 + 2] = 1;
  }
  return;
}

