/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
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
  int aiStack_24 [3];
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  puVar1 = (undefined4 *)
           (**(code **)(_r_modules_funcs_p + 0x40))(&ke_env,*(code **)(_r_modules_funcs_p + 0x40));
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  if (puVar1 == (undefined4 *)0x0) goto _L23;
  *puVar1 = 0xffffffff;
  iVar2 = (**(code **)(_r_modules_funcs_p + 0x11c))(puVar1,*(code **)(_r_modules_funcs_p + 0x11c));
  if (iVar2 != 0) {
    (**(code **)(_r_plf_funcs_p + 0xc))
              (*(undefined2 *)(puVar1 + 1),*(undefined2 *)((int)puVar1 + 6),"ke_task.c",0xb1,
               *(code **)(_r_plf_funcs_p + 0xc));
    goto _L23;
  }
  pcVar3 = (code *)(**(code **)(_r_modules_funcs_p + 0x3cc))
                             (puVar1,*(code **)(_r_modules_funcs_p + 0x3cc));
  if (pcVar3 == (code *)0x0) {
    (**(code **)(_r_plf_funcs_p + 0x10))
              (*(undefined2 *)(puVar1 + 1),*(undefined2 *)((int)puVar1 + 6),"ke_task.c",0xb8,
               *(code **)(_r_plf_funcs_p + 0x10));
    aiStack_24[0] = 0;
_L27:
    (**(code **)(_r_modules_funcs_p + 0xd8))(puVar1,*(code **)(_r_modules_funcs_p + 0xd8));
  }
  else {
    (**(code **)(_r_modules_funcs_p + 0x3c4))(puVar1,*(code **)(_r_modules_funcs_p + 0x3c4));
    aiStack_24[0] =
         (*pcVar3)(*(undefined2 *)(puVar1 + 1),puVar1 + 3,*(undefined2 *)((int)puVar1 + 6),
                   *(undefined2 *)(puVar1 + 2));
    (**(code **)(_r_modules_funcs_p + 0x3c8))
              (aiStack_24,puVar1,*(code **)(_r_modules_funcs_p + 0x3c8));
    if (aiStack_24[0] == 2) {
      (**(code **)(_r_modules_funcs_p + 0x44))(&ke_env,puVar1,*(code **)(_r_modules_funcs_p + 0x44))
      ;
      goto _L23;
    }
    if (aiStack_24[0] < 3) {
      if (aiStack_24[0] == 0) goto _L27;
      if (aiStack_24[0] == 1) goto _L23;
    }
    (**(code **)(_r_plf_funcs_p + 8))(0,"ke_task.c",0xdc,*(code **)(_r_plf_funcs_p + 8));
  }
_L23:
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  if (_ke_env == 0) {
    (**(code **)(_r_modules_funcs_p + 0xec))(3,*(code **)(_r_modules_funcs_p + 0xec));
  }
                    /* WARNING: Could not recover jumptable at 0x000101c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return;
}

