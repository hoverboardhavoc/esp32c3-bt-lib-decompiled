/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_tx_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_con_tx_eco(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1 * 4;
  iVar2 = *(int *)(&lld_con_env + iVar1);
  r_lld_con_tx();
  if (((*(char *)(&lld_con_cntl_pkt_info + param_1) != '\0') &&
      (*(char *)((int)&lld_con_cntl_pkt_info + iVar1 + 2) == '\0')) &&
     (param_1 * 9 + (uint)*(byte *)(iVar2 + 0x90) ==
      (uint)*(byte *)((int)&lld_con_cntl_pkt_info + iVar1 + 1))) {
    *(undefined1 *)((int)&lld_con_cntl_pkt_info + iVar1 + 2) = 1;
  }
  return;
}

