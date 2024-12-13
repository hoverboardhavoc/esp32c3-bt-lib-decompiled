/*
 * Last changed at upstream commit c57c0b11c3c0065a16b66685715100a189ef9b27
 * https://github.com/espressif/esp32c3-bt-lib/commit/c57c0b11c3c0065a16b66685715100a189ef9b27
 * Upstream date: 2024-12-13 13:39:25 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(555b0a2)
 * Source: libbtdm_app -> llm_scan.o -> llm_adv_reports_list_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void llm_adv_reports_list_remove(undefined4 param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  void *__s;
  int iVar3;
  
  if ((*(int *)(_p_llm_env + 0xcc) != 0) && (*(char *)(_p_llm_env + 0xd0) != '\0')) {
    iVar1 = 0;
    while( true ) {
      if ((int)(uint)*(byte *)(_p_llm_env + 0xd2) <= iVar1) break;
      iVar3 = iVar1 * 0xe;
      iVar2 = (*(code *)*_r_modules_funcs_p)
                        (param_1,*(int *)(_p_llm_env + 0xcc) + iVar3,(code *)*_r_modules_funcs_p);
      if ((((iVar2 != 0) &&
           (__s = (void *)(*(int *)(_p_llm_env + 0xcc) + iVar3),
           *(byte *)((int)__s + 0xb) == param_2)) && (*(byte *)((int)__s + 10) == param_3)) &&
         (*(byte *)((int)__s + 0xc) == param_4)) {
        memset(__s,0,6);
        iVar3 = *(int *)(_p_llm_env + 0xcc) + iVar3;
        *(undefined2 *)(iVar3 + 10) = 0xffff;
        *(undefined1 *)(iVar3 + 0xc) = 0xff;
      }
      iVar1 = iVar1 + 1;
    }
  }
  return;
}

