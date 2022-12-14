/*
 * Last changed at upstream commit bba9af9259e0999ef246426d31a793fe0a3ff4db
 * https://github.com/espressif/esp32c3-bt-lib/commit/bba9af9259e0999ef246426d31a793fe0a3ff4db
 * Upstream date: 2022-12-14 15:32:37 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(80abacdd)
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
  uint uVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  char acStack_60 [6];
  char cStack_5a;
  char cStack_59;
  char acStack_58 [6];
  char acStack_52 [42];
  
  pcVar4 = acStack_60;
  if (*(char *)(_p_llm_env + 0xd7) != '\x01') {
    return 1;
  }
  if ((*(byte *)(_p_llm_env + 0xd4) & 1) == 0) {
    return 1;
  }
  cVar1 = (&adv_evt_prop2type)[*(byte *)(param_1 + 0x15)];
  if (DAT_00012060 != '\0') {
    llm_util_flush_list(&le_scan_duplicate_option);
    (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
    DAT_00012060 = '\0';
    (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  }
  if ((DAT_00012061 != '\0') && (llm_util_flush_list != (code)0x0)) {
    llm_util_flush_list(&le_scan_duplicate_option);
    (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
    DAT_00012061 = '\0';
    (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  }
  uVar10 = (uint)*(byte *)(param_1 + 0x20);
  cVar2 = *(char *)(param_1 + 0x17);
  memset(acStack_52,0,0x21);
  uVar9 = uVar10;
  if (0x1f < uVar10) {
    uVar9 = 0x1f;
  }
  memcpy(acStack_58,param_2,6);
  memcpy(acStack_52,(void *)((uint)*(byte *)(param_1 + 0x28) + *(int *)(param_1 + 0x24)),uVar9);
  uVar11 = uVar9 + 8;
  acStack_52[uVar9] = cVar1;
  acStack_52[uVar9 + 1] = cVar2;
  uVar3 = llm_adv_is_in_duplicate_scan_duplicate_exceptional_list(acStack_58,uVar11 & 0xff);
  if (uVar3 != 0) {
    return uVar3;
  }
  if ((((llm_util_flush_list != (code)0x0) && (cVar1 == '\x03')) && (acStack_52[1] == '*')) &&
     (0xb < uVar10)) {
    uVar9 = llm_util_check_mesh_adv_report_list(acStack_52,uVar9);
    return (uVar9 ^ 1) & 0xff;
  }
  if (DAT_00012045 == '\x01') {
    uVar11 = uVar9 + 2;
    pcVar4 = acStack_52;
  }
  else if (DAT_00012045 == '\x02') {
    pcVar4 = acStack_58;
  }
  else {
    memcpy(acStack_60,param_2,6);
    uVar11 = 8;
    cStack_5a = cVar1;
    cStack_59 = cVar2;
  }
  iVar5 = hash_function_blob(pcVar4,uVar11);
  for (piVar8 = (int *)_le_scan_duplicate_option; piVar8 != (int *)0x0; piVar8 = (int *)*piVar8) {
    if (iVar5 == piVar8[1]) {
      uVar9 = 1;
      goto _L327;
    }
  }
  uVar10 = (**(code **)(_r_modules_funcs_p + 0x50))
                     (&le_scan_duplicate_option,*(code **)(_r_modules_funcs_p + 0x50));
  iVar6 = _adv_evt_prop2type;
  uVar9 = 0;
  if (uVar10 < _DAT_00012046) {
    iVar6 = (**(code **)(_r_modules_funcs_p + 0x120))(8,3,*(code **)(_r_modules_funcs_p + 0x120));
    if (iVar6 == 0) goto _L327;
  }
  else {
    if (_adv_evt_prop2type == 0) goto _L327;
    iVar7 = (**(code **)(_r_modules_funcs_p + 0x1c))
                      (&le_scan_duplicate_option,_adv_evt_prop2type,
                       *(code **)(_r_modules_funcs_p + 0x1c));
    if (iVar7 == 0) {
      (**(code **)(_r_plf_funcs_p + 8))("llm_scan.c",0x52c,*(code **)(_r_plf_funcs_p + 8));
    }
  }
  iVar7 = _r_modules_funcs_p;
  *(int *)(iVar6 + 4) = iVar5;
  (**(code **)(iVar7 + 0x4c))(&le_scan_duplicate_option,iVar6,*(code **)(iVar7 + 0x4c));
_L327:
  return uVar9 ^ 1;
}

