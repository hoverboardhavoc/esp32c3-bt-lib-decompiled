/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_set_tx_power
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_set_tx_power(int param_1,undefined4 param_2)

{
  ushort uVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  
  uVar3 = (*_r_ke_free)(param_2,param_1,_r_ke_free);
  iVar4 = r_emi_get_mem_addr_by_offset(0x400);
  iVar2 = param_1 * 0x5a + 0x18;
  uVar1 = *(ushort *)(iVar4 + iVar2);
  iVar4 = r_emi_get_mem_addr_by_offset(0x400);
  *(ushort *)(iVar4 + iVar2) = uVar1 & 0xff00 | uVar3;
  return;
}

