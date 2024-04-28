/*
 * Last changed at upstream commit 4b1338827fa19fbacc02dd9e46e76be2b0dd17a9
 * https://github.com/espressif/esp32c3-bt-lib/commit/4b1338827fa19fbacc02dd9e46e76be2b0dd17a9
 * Upstream date: 2024-04-28 11:58:26 +0800
 * Upstream subject: fix(coex): Fixed some coexist issues(ba3b3e3)
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
                  (*(undefined2 *)(puVar1 + 1),*(undefined2 *)((int)puVar1 + 6),"ke_task.c",0xac,
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
        if (aiStack_24[0] == 1) goto _L19;
        if (aiStack_24[0] == 2) {
          (**(code **)(_r_modules_funcs_p + 0x44))
                    (&ke_env,puVar1,*(code **)(_r_modules_funcs_p + 0x44));
          goto _L19;
        }
        if (aiStack_24[0] != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"ke_task.c",0xcf,*(code **)(_r_plf_funcs_p + 8));
          goto _L19;
        }
      }
      (**(code **)(_r_modules_funcs_p + 0xd8))(puVar1,*(code **)(_r_modules_funcs_p + 0xd8));
    }
    else {
      (**(code **)(_r_plf_funcs_p + 0xc))
                (*(undefined2 *)(puVar1 + 1),*(undefined2 *)((int)puVar1 + 6),"ke_task.c",0xa5,
                 *(code **)(_r_plf_funcs_p + 0xc));
    }
  }
_L19:
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  if (_ke_env == 0) {
    (**(code **)(_r_modules_funcs_p + 0xec))(3,*(code **)(_r_modules_funcs_p + 0xec));
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

