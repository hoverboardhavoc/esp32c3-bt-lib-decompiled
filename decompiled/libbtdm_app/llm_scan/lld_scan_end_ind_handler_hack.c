/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_scan.o -> lld_scan_end_ind_handler_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_scan_end_ind_handler_hack(int param_1)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  
  iVar5 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar5 + 0x23) == '\0') {
    return 0;
  }
  bVar1 = *(byte *)(param_1 + 1);
  iVar5 = (uint)bVar1 * 0x44;
  iVar6 = *(int *)(_p_llm_env + 8) + iVar5;
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
    if (*(char *)(iVar6 + 0x40) != '\b') {
      (**(code **)(_r_plf_funcs_p + 8))(0,"llm_scan.c",0x81f,*(code **)(_r_plf_funcs_p + 8));
      goto _L614;
    }
    pcVar7 = *(code **)(_r_ip_funcs_p + 0x4b8);
    uVar3 = 0x200c;
  }
  else {
    if (*(char *)(iVar6 + 0x40) != '\b') {
      if (*(ushort *)(iVar6 + 0x2a) == 0) {
        puVar4 = (undefined1 *)
                 (**(code **)(_r_modules_funcs_p + 200))
                           (0x1104,0,0x3e,1,*(code **)(_r_modules_funcs_p + 200));
        *puVar4 = 0x11;
        (**(code **)(_r_ip_funcs_p + 0x8c))(*(code **)(_r_ip_funcs_p + 0x8c));
        *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar5 + 0x40) = 6;
      }
      else {
        (**(code **)(_r_modules_funcs_p + 0xc4))
                  (3,0,(uint)*(ushort *)(iVar6 + 0x2a) * 0x80 - (uint)*(ushort *)(iVar6 + 0x28),
                   *(code **)(_r_modules_funcs_p + 0xc4));
      }
      if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
         ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
        (*(code *)*_bt_rf_coex_hooks_p)((uint)bVar1,3,0);
      }
      goto _L614;
    }
    pcVar7 = *(code **)(_r_ip_funcs_p + 0x4b8);
    uVar3 = 0x2042;
  }
  (*pcVar7)(uVar3,0,pcVar7);
  *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar5 + 0x40) = 6;
_L614:
  iVar6 = _p_llm_env;
  cVar2 = *(char *)(*(int *)(_p_llm_env + 8) + iVar5 + 0x40);
  if ((cVar2 == '\x06') || ((*(byte *)(_p_llm_env + 0xd4) & 2) != 0)) {
    *(undefined1 *)(_p_llm_env + 0xd2) = 0;
    *(undefined1 *)(iVar6 + 0xd1) = 0;
    if (cVar2 == '\x06') {
      (**(code **)(_r_ip_funcs_p + 0x53c))(*(code **)(_r_ip_funcs_p + 0x53c));
    }
  }
  return 0;
}

