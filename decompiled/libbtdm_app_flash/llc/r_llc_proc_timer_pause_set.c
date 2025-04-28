/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc.o -> r_llc_proc_timer_pause_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_proc_timer_pause_set(uint param_1,uint param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  bool bVar3;
  undefined2 uVar4;
  int iVar5;
  
  iVar5 = *(int *)(&llc_env + param_1 * 4);
  if (1 < param_2) {
    r_assert_param("llc.c",0x282);
  }
  if ((iVar5 != 0) && (iVar5 = *(int *)(*(int *)(&llc_env + param_1 * 4) + param_2 * 4), iVar5 != 0)
     ) {
    bVar1 = *(byte *)(iVar5 + 6);
    if (bVar1 == 2) {
      if (param_3 == 0) {
        *(undefined1 *)(iVar5 + 6) = 1;
        bVar3 = true;
_L207:
        iVar5 = (param_2 != 0) + 0x100;
        if (!bVar3) {
          r_ke_timer_clear(iVar5);
          return;
        }
        iVar2 = r_sdk_config_get_opts();
        if (((param_1 < *(byte *)(iVar2 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
           ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
          uVar4 = 4000;
        }
        else {
          uVar4 = *(undefined2 *)(*(int *)(&llc_env + param_1 * 4) + 0x12);
        }
        r_ke_timer_set(iVar5,param_1 << 8 | 1,uVar4);
        return;
      }
    }
    else if (bVar1 < 3) {
      if (bVar1 == 0) {
        if (param_3 != 0) {
          *(undefined1 *)(iVar5 + 6) = 3;
        }
      }
      else if (param_3 != 0) {
        *(undefined1 *)(iVar5 + 6) = 2;
        bVar3 = false;
        goto _L207;
      }
    }
    else {
      if (bVar1 != 3) {
        r_assert_param(*(undefined1 *)(iVar5 + 4),"llc.c",0x2b6);
        return;
      }
      if (param_3 == 0) {
        *(undefined1 *)(iVar5 + 6) = 0;
      }
    }
  }
  return;
}

