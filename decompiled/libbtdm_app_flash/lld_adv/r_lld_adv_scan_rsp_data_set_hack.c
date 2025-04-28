/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_scan_rsp_data_set_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_adv_scan_rsp_data_set_hack
               (int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(&lld_adv_env + param_1 * 4);
  iVar2 = r_emi_get_mem_addr_by_offset(0x1400);
  sVar1 = *(short *)((param_1 * 9 + 1) * 0xe + 4 + iVar2);
  r_lld_adv_scan_rsp_data_set(param_1,param_2,param_3,param_4,param_5);
  if (((((*(ushort *)(iVar3 + 0x74) & 0x10) != 0) && (param_4 != 0)) && (sVar1 != 0)) &&
     (*(short *)(iVar3 + 0x80) == sVar1)) {
    *(undefined2 *)(iVar3 + 0x80) = 0;
  }
  return;
}

