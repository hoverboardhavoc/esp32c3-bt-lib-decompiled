/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_scan.o -> hci_le_per_adv_create_sync_cancel_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_per_adv_create_sync_cancel_cmd_handler(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  iVar2 = _r_ip_funcs_p;
  if (*(char *)(iVar4 + 0x18) == '\0') {
    (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,0xc,*(code **)(_r_ip_funcs_p + 0x4b8));
    return 0;
  }
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
    uVar1 = 0;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar1 = (**(code **)(iVar2 + 0x510))(*(code **)(iVar2 + 0x510));
    iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (uVar1 < *(byte *)(iVar2 + 0xd)) {
      iVar2 = (**(code **)(_r_ip_funcs_p + 0x3e0))(uVar1,*(code **)(_r_ip_funcs_p + 0x3e0));
      if (iVar2 != 0) {
        iVar2 = (**(code **)(_r_ip_funcs_p + 0x174))(uVar1,*(code **)(_r_ip_funcs_p + 0x174));
        if (iVar2 != 0) {
          (**(code **)(_r_modules_funcs_p + 0xd0))
                    (param_1,0,param_2,*(code **)(_r_modules_funcs_p + 0xd0));
          return 1;
        }
        if (_bt_rf_coex_hooks_p == (undefined4 *)0x0) {
          return 0;
        }
        if ((code *)*_bt_rf_coex_hooks_p == (code *)0x0) {
          return 0;
        }
        (*(code *)*_bt_rf_coex_hooks_p)(uVar1,5,0);
        return 0;
      }
      piVar5 = (int *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44);
      *(undefined1 *)(piVar5 + 0x10) = 0;
      (**(code **)(_r_modules_funcs_p + 0xd8))(*piVar5 + -0xc,*(code **)(_r_modules_funcs_p + 0xd8))
      ;
      *(undefined4 *)(*(int *)(_p_llm_env + 8) + uVar1 * 0x44) = 0;
      iVar2 = 0;
      if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
         ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
        (*(code *)*_bt_rf_coex_hooks_p)(uVar1,6,0);
      }
      goto _L192;
    }
  }
  iVar2 = 0xc;
_L192:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,iVar2,*(code **)(_r_ip_funcs_p + 0x4b8));
  if (iVar2 == 0) {
    puVar3 = (undefined2 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x1104,0,0x3e,0x12,*(code **)(_r_modules_funcs_p + 200));
    *puVar3 = 0x440e;
    iVar2 = _p_llm_env;
    puVar3[1] = (short)uVar1;
    iVar2 = *(int *)(iVar2 + 8) + uVar1 * 0x44;
    *(undefined1 *)(puVar3 + 2) = *(undefined1 *)(iVar2 + 0x28);
    *(undefined1 *)((int)puVar3 + 5) = *(undefined1 *)(iVar2 + 0x41);
    memcpy(puVar3 + 3,(void *)(iVar2 + 4),6);
    *(undefined1 *)(puVar3 + 6) = 1;
    puVar3[7] = 6;
    iVar2 = _r_ip_funcs_p;
    *(undefined1 *)(puVar3 + 8) = 0;
    (**(code **)(iVar2 + 0x8c))(puVar3,*(code **)(iVar2 + 0x8c));
  }
  return 0;
}

