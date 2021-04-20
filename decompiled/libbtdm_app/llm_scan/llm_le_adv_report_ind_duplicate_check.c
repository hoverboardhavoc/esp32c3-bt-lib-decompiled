/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> llm_scan.o -> llm_le_adv_report_ind_duplicate_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint llm_le_adv_report_ind_duplicate_check(int param_1,void *param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint __n;
  uint uVar9;
  uint uVar10;
  char acStack_60 [6];
  char cStack_5a;
  char cStack_59;
  char acStack_58 [6];
  char acStack_52 [42];
  
  pcVar5 = acStack_60;
  uVar4 = 1;
  if ((*(char *)(_p_llm_env + 0xd7) == '\x01') &&
     (uVar4 = 1, (*(byte *)(_p_llm_env + 0xd4) & 1) != 0)) {
    cVar1 = (&adv_evt_prop2type)[*(byte *)(param_1 + 0x15)];
    if (DAT_00012050 != '\0') {
      llm_util_flush_list(&le_scan_duplicate_option);
      (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
      DAT_00012050 = '\0';
      (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
    }
    if ((DAT_00012051 != '\0') && (adv_evt_prop2type != '\0')) {
      llm_util_flush_list(&le_scan_duplicate_option);
      (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
      DAT_00012051 = '\0';
      (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
    }
    uVar9 = (uint)*(byte *)(param_1 + 0x20);
    cVar2 = *(char *)(param_1 + 0x17);
    memset(acStack_52,0,0x21);
    __n = uVar9;
    if (0x1f < uVar9) {
      __n = 0x1f;
    }
    memcpy(acStack_58,param_2,6);
    memcpy(acStack_52,(void *)((uint)*(byte *)(param_1 + 0x28) + *(int *)(param_1 + 0x24)),__n);
    uVar10 = __n + 8;
    acStack_52[__n] = cVar1;
    acStack_52[__n + 1] = cVar2;
    uVar4 = llm_adv_is_in_duplicate_scan_duplicate_exceptional_list(acStack_58,uVar10 & 0xff);
    if (uVar4 == 0) {
      if ((((adv_evt_prop2type == '\0') || (cVar1 != '\x03')) || (acStack_52[1] != '*')) ||
         (uVar9 < 0xc)) {
        if (DAT_00012035 == '\x01') {
          uVar10 = __n + 2;
          pcVar5 = acStack_52;
        }
        else if (DAT_00012035 == '\x02') {
          pcVar5 = acStack_58;
        }
        else {
          memcpy(acStack_60,param_2,6);
          uVar10 = 8;
          cStack_5a = cVar1;
          cStack_59 = cVar2;
        }
        iVar6 = hash_function_blob(pcVar5,uVar10);
        for (piVar8 = (int *)_le_scan_duplicate_option; piVar8 != (int *)0x0;
            piVar8 = (int *)*piVar8) {
          if (iVar6 == piVar8[1]) {
            uVar4 = 1;
            goto _L294;
          }
        }
        uVar4 = (**(code **)(_r_modules_funcs_p + 0x50))
                          (&le_scan_duplicate_option,*(code **)(_r_modules_funcs_p + 0x50));
        if (_DAT_00012036 <= uVar4) {
          llm_util_flush_list(&le_scan_duplicate_option);
        }
        iVar7 = (**(code **)(_r_modules_funcs_p + 0x120))
                          (8,0,*(code **)(_r_modules_funcs_p + 0x120));
        iVar3 = _r_modules_funcs_p;
        uVar4 = 0;
        if (iVar7 != 0) {
          *(int *)(iVar7 + 4) = iVar6;
          (**(code **)(iVar3 + 0x4c))(&le_scan_duplicate_option,iVar7,*(code **)(iVar3 + 0x4c));
        }
_L294:
        uVar4 = uVar4 ^ 1;
      }
      else {
        uVar4 = llm_util_check_mesh_adv_report_list(acStack_52,__n);
        uVar4 = (uVar4 ^ 1) & 0xff;
      }
    }
  }
  return uVar4;
}

