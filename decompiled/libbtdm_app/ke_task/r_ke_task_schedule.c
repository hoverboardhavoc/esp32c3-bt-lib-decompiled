/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> ke_task.o -> r_ke_task_schedule
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_task_schedule(void)

{
  undefined4 *puVar1;
  int iVar2;
  code *pcVar3;
  int aiStack_24 [3];
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  puVar1 = (undefined4 *)
           (**(code **)(_r_modules_funcs_p + 0x40))(&ke_env,*(code **)(_r_modules_funcs_p + 0x40));
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0xffffffff;
    iVar2 = (**(code **)(_r_modules_funcs_p + 0x11c))(puVar1,*(code **)(_r_modules_funcs_p + 0x11c))
    ;
    if (iVar2 == 0) {
      pcVar3 = (code *)(**(code **)(_r_modules_funcs_p + 0x3cc))
                                 (puVar1,*(code **)(_r_modules_funcs_p + 0x3cc));
      if (pcVar3 == (code *)0x0) {
        (**(code **)(_r_plf_funcs_p + 0x10))
                  (*(undefined2 *)(puVar1 + 1),*(undefined2 *)((int)puVar1 + 6),"ke_task.c",0x9d,
                   *(code **)(_r_plf_funcs_p + 0x10));
        aiStack_24[0] = 0;
      }
      else {
        (**(code **)(_r_modules_funcs_p + 0x3c4))(puVar1,*(code **)(_r_modules_funcs_p + 0x3c4));
        aiStack_24[0] =
             (*pcVar3)(*(undefined2 *)(puVar1 + 1),puVar1 + 3,*(undefined2 *)((int)puVar1 + 6),
                       *(undefined2 *)(puVar1 + 2));
        (**(code **)(_r_modules_funcs_p + 0x3c8))
                  (aiStack_24,puVar1,*(code **)(_r_modules_funcs_p + 0x3c8));
        if (aiStack_24[0] == 1) goto _L14;
        if (aiStack_24[0] == 2) {
          (**(code **)(_r_modules_funcs_p + 0x44))
                    (&ke_env,puVar1,*(code **)(_r_modules_funcs_p + 0x44));
          goto _L14;
        }
        if (aiStack_24[0] != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"ke_task.c",0xc0,*(code **)(_r_plf_funcs_p + 8));
          goto _L14;
        }
      }
      (**(code **)(_r_modules_funcs_p + 0xd8))(puVar1,*(code **)(_r_modules_funcs_p + 0xd8));
    }
    else {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (*(undefined2 *)(puVar1 + 1),*(undefined2 *)((int)puVar1 + 6),"ke_task.c",0x96,
                 *(code **)(_r_plf_funcs_p + 0xc));
    }
  }
_L14:
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  if (_ke_env == 0) {
    (**(code **)(_r_modules_funcs_p + 0xec))(3,*(code **)(_r_modules_funcs_p + 0xec));
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

