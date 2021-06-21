/*
 * Last changed at upstream commit f45e6918026b6e8fdc6dec3f626a98c35960f50e
 * https://github.com/espressif/esp32c3-bt-lib/commit/f45e6918026b6e8fdc6dec3f626a98c35960f50e
 * Upstream date: 2021-06-21 17:00:22 +0530
 * Upstream subject: Fix MIC error issue during start_encryption procedure Update ESP32C3 and ESP32S3 libraries (a86af1e)
 * Source: libbtdm_app -> ke_task.o -> r_ke_task_schedule_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ke_task_schedule_hack(void)

{
  undefined4 *puVar1;
  int iVar2;
  code *pcVar3;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  puVar1 = (undefined4 *)
           (**(code **)(_r_modules_funcs_p + 0x40))(&ke_env,*(code **)(_r_modules_funcs_p + 0x40));
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0xffffffff;
    iVar2 = (**(code **)(_r_modules_funcs_p + 0x11c))(puVar1,*(code **)(_r_modules_funcs_p + 0x11c))
    ;
    if (iVar2 == 0) {
      pcVar3 = (code *)ke_task_handler_get_hack(puVar1);
      if (pcVar3 == (code *)0x0) {
        (**(code **)(_r_plf_funcs_p + 0x10))
                  (*(undefined2 *)(puVar1 + 1),*(undefined2 *)((int)puVar1 + 6),"ke_task.c",0x93,
                   *(code **)(_r_plf_funcs_p + 0x10));
      }
      else {
        ke_task_handler_pre(puVar1);
        iVar2 = (*pcVar3)(*(undefined2 *)(puVar1 + 1),puVar1 + 3,*(undefined2 *)((int)puVar1 + 6),
                          *(undefined2 *)(puVar1 + 2));
        if (iVar2 == 1) goto _L8;
        if (iVar2 == 2) {
          (**(code **)(_r_modules_funcs_p + 0x44))
                    (&ke_env,puVar1,*(code **)(_r_modules_funcs_p + 0x44));
          goto _L8;
        }
        if (iVar2 != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"ke_task.c",0xb5,*(code **)(_r_plf_funcs_p + 8));
          goto _L8;
        }
      }
      (**(code **)(_r_modules_funcs_p + 0xd8))(puVar1,*(code **)(_r_modules_funcs_p + 0xd8));
    }
    else {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (*(undefined2 *)(puVar1 + 1),*(undefined2 *)((int)puVar1 + 6),"ke_task.c",0x8c,
                 *(code **)(_r_plf_funcs_p + 0xc));
    }
  }
_L8:
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  if (_ke_env == 0) {
    (**(code **)(_r_modules_funcs_p + 0xec))(3,*(code **)(_r_modules_funcs_p + 0xec));
  }
                    /* WARNING: Could not recover jumptable at 0x000100fe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

