/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> llm_scan.o -> hci_le_per_adv_create_sync_cancel_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_per_adv_create_sync_cancel_cmd_handler(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined2 *puVar4;
  int *piVar5;
  code *pcVar6;
  
  iVar3 = _r_ip_funcs_p;
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
    uVar2 = 0;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    uVar2 = (**(code **)(iVar3 + 0x510))(*(code **)(iVar3 + 0x510));
    iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (uVar2 < *(byte *)(iVar3 + 0xd)) {
      iVar3 = (**(code **)(_r_ip_funcs_p + 0x3e0))(uVar2,*(code **)(_r_ip_funcs_p + 0x3e0));
      if (iVar3 != 0) {
        iVar3 = (**(code **)(_r_ip_funcs_p + 0x174))(uVar2,*(code **)(_r_ip_funcs_p + 0x174));
        if (iVar3 != 0) {
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
        (*(code *)*_bt_rf_coex_hooks_p)(uVar2,5,0);
        return 0;
      }
      piVar5 = (int *)(*(int *)(_p_llm_env + 8) + uVar2 * 0x44);
      *(undefined1 *)(piVar5 + 0x10) = 0;
      (**(code **)(_r_modules_funcs_p + 0xd8))(*piVar5 + -0xc,*(code **)(_r_modules_funcs_p + 0xd8))
      ;
      puVar1 = _bt_rf_coex_hooks_p;
      *(undefined4 *)(uVar2 * 0x44 + *(int *)(_p_llm_env + 8)) = 0;
      iVar3 = 0;
      if ((puVar1 != (undefined4 *)0x0) && (pcVar6 = (code *)*puVar1, pcVar6 != (code *)0x0)) {
        (*pcVar6)(uVar2,6,0);
      }
      goto _L181;
    }
  }
  iVar3 = 0xc;
_L181:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,iVar3,*(code **)(_r_ip_funcs_p + 0x4b8));
  if (iVar3 == 0) {
    puVar4 = (undefined2 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x1104,0,0x3e,0x12,*(code **)(_r_modules_funcs_p + 200));
    puVar4[1] = (short)uVar2;
    *puVar4 = 0x440e;
    iVar3 = *(int *)(_p_llm_env + 8) + uVar2 * 0x44;
    *(undefined1 *)(puVar4 + 2) = *(undefined1 *)(iVar3 + 0x28);
    *(undefined1 *)((int)puVar4 + 5) = *(undefined1 *)(iVar3 + 0x41);
    memcpy(puVar4 + 3,(void *)(iVar3 + 4),6);
    *(undefined1 *)(puVar4 + 6) = 1;
    puVar4[7] = 6;
    iVar3 = _r_ip_funcs_p;
    *(undefined1 *)(puVar4 + 8) = 0;
    (**(code **)(iVar3 + 0x8c))(puVar4,*(code **)(iVar3 + 0x8c));
  }
  return 0;
}

