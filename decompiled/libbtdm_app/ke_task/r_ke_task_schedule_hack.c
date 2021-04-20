/*
 * Last changed at upstream commit 022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * https://github.com/espressif/esp32c3-bt-lib/commit/022b7da7fcf0043f891c2e8ccd8c241243018e2f
 * Upstream date: 2021-04-20 16:00:04 +0800
 * Upstream subject: ESP32-C3, ESP32-S3: update libbtdm_app.a(d1d0c6f1)
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
                  (*(undefined2 *)(puVar1 + 1),*(undefined2 *)((int)puVar1 + 6),"ke_task.c",0x8f,
                   *(code **)(_r_plf_funcs_p + 0x10));
      }
      else {
        ke_task_handler_pre(puVar1);
        iVar2 = (*pcVar3)(*(undefined2 *)(puVar1 + 1),puVar1 + 3,*(undefined2 *)((int)puVar1 + 6),
                          *(undefined2 *)(puVar1 + 2));
        if (iVar2 == 1) goto _L6;
        if (iVar2 == 2) {
          (**(code **)(_r_modules_funcs_p + 0x44))
                    (&ke_env,puVar1,*(code **)(_r_modules_funcs_p + 0x44));
          goto _L6;
        }
        if (iVar2 != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"ke_task.c",0xb1,*(code **)(_r_plf_funcs_p + 8));
          goto _L6;
        }
      }
      (**(code **)(_r_modules_funcs_p + 0xd8))(puVar1,*(code **)(_r_modules_funcs_p + 0xd8));
    }
    else {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (*(undefined2 *)(puVar1 + 1),*(undefined2 *)((int)puVar1 + 6),"ke_task.c",0x88,
                 *(code **)(_r_plf_funcs_p + 0xc));
    }
  }
_L6:
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  if (_ke_env == 0) {
    (**(code **)(_r_modules_funcs_p + 0xec))(3,*(code **)(_r_modules_funcs_p + 0xec));
  }
                    /* WARNING: Could not recover jumptable at 0x000100ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

