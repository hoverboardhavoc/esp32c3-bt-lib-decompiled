/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> llc.o -> r_llc_proc_timer_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_proc_timer_set(uint param_1,uint param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  undefined2 uVar5;
  undefined1 uVar6;
  int iVar7;
  
  iVar7 = *(int *)(&llc_env + param_1 * 4);
  if (1 < param_2) {
    r_assert_param("llc.c",0x231);
  }
  if (iVar7 == 0) {
    return;
  }
  iVar7 = *(int *)(*(int *)(&llc_env + param_1 * 4) + param_2 * 4);
  if (iVar7 == 0) {
    return;
  }
  cVar1 = *(char *)(iVar7 + 6);
  if (cVar1 == '\x01') {
    if (param_3 == 0) {
      *(undefined1 *)(iVar7 + 6) = 0;
      bVar4 = false;
      goto _L173;
    }
  }
  else {
    if (cVar1 != '\0') {
      uVar6 = 2;
      if (cVar1 == '\x02') {
        uVar6 = 3;
        if (param_3 != 0) {
          return;
        }
      }
      else {
        if (cVar1 != '\x03') {
          r_assert_param(*(undefined1 *)(iVar7 + 4),"llc.c",0x269);
          return;
        }
        if (param_3 == 0) {
          return;
        }
      }
      *(undefined1 *)(iVar7 + 6) = uVar6;
      return;
    }
    if (param_3 == 0) {
      return;
    }
    *(undefined1 *)(iVar7 + 6) = 1;
  }
  bVar4 = true;
_L173:
  uVar2 = param_1 << 8 | 1;
  iVar7 = (param_2 != 0) + 0x100;
  if (!bVar4) {
    r_ke_timer_clear(iVar7,uVar2);
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
  r_ke_timer_set(iVar7,uVar2,uVar5);
  return;
}

