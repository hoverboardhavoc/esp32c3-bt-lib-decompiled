/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> llc.o -> r_llc_proc_timer_pause_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_proc_timer_pause_set(uint param_1,uint param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  undefined2 uVar5;
  int iVar6;
  
  iVar6 = *(int *)(&llc_env + param_1 * 4);
  if (1 < param_2) {
    r_assert_param("llc.c",0x27f);
  }
  if ((iVar6 != 0) && (iVar6 = *(int *)(*(int *)(&llc_env + param_1 * 4) + param_2 * 4), iVar6 != 0)
     ) {
    cVar1 = *(char *)(iVar6 + 6);
    if (cVar1 == '\x01') {
      if (param_3 != 0) {
        *(undefined1 *)(iVar6 + 6) = 2;
        bVar4 = false;
_L204:
        uVar2 = param_1 << 8 | 1;
        iVar6 = (param_2 != 0) + 0x100;
        if (!bVar4) {
          r_ke_timer_clear(iVar6,uVar2);
          return;
        }
        iVar3 = r_sdk_config_get_opts();
        if (((param_1 < *(byte *)(iVar3 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
           ((*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x44) & 3) != 3)) {
          uVar5 = 4000;
        }
        else {
          uVar5 = *(undefined2 *)(*(int *)(&llc_env + param_1 * 4) + 0x12);
        }
        r_ke_timer_set(iVar6,uVar2,uVar5);
        return;
      }
    }
    else if (cVar1 == '\0') {
      if (param_3 != 0) {
        *(undefined1 *)(iVar6 + 6) = 3;
      }
    }
    else if (cVar1 == '\x02') {
      if (param_3 == 0) {
        *(undefined1 *)(iVar6 + 6) = 1;
        bVar4 = true;
        goto _L204;
      }
    }
    else {
      if (cVar1 != '\x03') {
        r_assert_param(*(undefined1 *)(iVar6 + 4),"llc.c",0x2b3);
        return;
      }
      if (param_3 == 0) {
        *(undefined1 *)(iVar6 + 6) = 0;
      }
    }
  }
  return;
}

