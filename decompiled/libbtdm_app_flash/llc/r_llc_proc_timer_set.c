/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llc.o -> r_llc_proc_timer_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_proc_timer_set(uint param_1,uint param_2,int param_3)

{
  byte bVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  int iVar4;
  
  iVar4 = *(int *)(&llc_env + param_1 * 4);
  if (1 < param_2) {
    r_assert_param("llc.c",0x23a);
  }
  if (iVar4 == 0) {
    return;
  }
  iVar4 = *(int *)(*(int *)(&llc_env + param_1 * 4) + param_2 * 4);
  if (iVar4 == 0) {
    return;
  }
  bVar1 = *(byte *)(iVar4 + 6);
  uVar3 = 2;
  if (bVar1 == 2) {
    uVar3 = 3;
    if (param_3 != 0) goto _L150;
  }
  else {
    if (bVar1 < 3) {
      if (bVar1 == 0) {
        if (param_3 == 0) goto _L150;
        *(undefined1 *)(iVar4 + 6) = 1;
_L151:
        uVar2 = 1;
      }
      else {
        if (param_3 != 0) goto _L151;
        *(undefined1 *)(iVar4 + 6) = 0;
        uVar2 = 0;
      }
      r_llc_llcp_trans_timer_set(param_1,param_2,uVar2);
      goto _L150;
    }
    if (bVar1 != 3) {
      r_assert_param(*(undefined1 *)(iVar4 + 4),"llc.c",0x272);
      goto _L150;
    }
    if (param_3 == 0) goto _L150;
  }
  *(undefined1 *)(iVar4 + 6) = uVar3;
_L150:
  r_ble_log_internal_x1
            (0x400f007b,
             (uint)*(byte *)(iVar4 + 6) << 0x18 | param_2 << 8 | param_3 << 0x10 | param_1);
  return;
}

