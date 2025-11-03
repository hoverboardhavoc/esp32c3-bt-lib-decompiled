/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> llm_scan.o -> llm_adv_reports_list_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void llm_adv_reports_list_remove(undefined4 param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  void *__s;
  int iVar3;
  
  if ((*(int *)(_p_llm_env + 0xcc) != 0) && (*(char *)(_p_llm_env + 0xd0) != '\0')) {
    uVar1 = 0;
    while( true ) {
      if ((int)(uint)*(byte *)(_p_llm_env + 0xd2) <= (int)uVar1) break;
      iVar3 = uVar1 * 0xe;
      iVar2 = r_co_bdaddr_compare(param_1,*(int *)(_p_llm_env + 0xcc) + iVar3);
      if ((((iVar2 != 0) &&
           (__s = (void *)(*(int *)(_p_llm_env + 0xcc) + iVar3),
           *(byte *)((int)__s + 0xb) == param_2)) && (*(byte *)((int)__s + 10) == param_3)) &&
         (*(byte *)((int)__s + 0xc) == param_4)) {
        memset(__s,0,6);
        iVar2 = _p_llm_env;
        iVar3 = *(int *)(_p_llm_env + 0xcc) + iVar3;
        *(undefined2 *)(iVar3 + 10) = 0xffff;
        *(undefined1 *)(iVar3 + 0xc) = 0xff;
        r_ble_log_internal_x1(0x20c1018e,(uint)*(byte *)(iVar2 + 0xd2) << 8 | uVar1);
      }
      uVar1 = uVar1 + 1;
    }
  }
  return;
}

