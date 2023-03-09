/*
 * Last changed at upstream commit 5c6ab5248a124cffc731a9e4764473fdeef38054
 * https://github.com/espressif/esp32c3-bt-lib/commit/5c6ab5248a124cffc731a9e4764473fdeef38054
 * Upstream date: 2023-03-09 14:58:19 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(85a1090)
 * Source: libbtdm_app -> llm_scan.o -> r_llm_le_adv_report_ind_duplicate_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_llm_le_adv_report_ind_duplicate_check(int param_1,void *param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  char acStack_50 [6];
  char cStack_4a;
  char cStack_49;
  char acStack_48 [6];
  char acStack_42 [34];
  
  pcVar7 = acStack_50;
  if ((*(char *)(_p_llm_env + 0xd7) == '\x01') &&
     (iVar6 = (**(code **)(_r_ip_funcs_p + 0x924))(*(code **)(_r_ip_funcs_p + 0x924)),
     (*(byte *)(_p_llm_env + 0xd4) & 1) != 0)) {
    cVar1 = (&adv_evt_prop2type)[*(byte *)(param_1 + 0x15)];
    if (*(char *)(iVar6 + 0x24) != '\0') {
      llm_util_flush_list();
      (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
      iVar3 = _r_osi_funcs_p;
      *(undefined1 *)(iVar6 + 0x24) = 0;
      (**(code **)(iVar3 + 0x18))(*(code **)(iVar3 + 0x18));
    }
    if ((*(char *)(iVar6 + 0x25) != '\0') && (*(char *)(iVar6 + 8) != '\0')) {
      llm_util_flush_list(iVar6 + 0x10);
      (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
      iVar3 = _r_osi_funcs_p;
      *(undefined1 *)(iVar6 + 0x25) = 0;
      (**(code **)(iVar3 + 0x18))(*(code **)(iVar3 + 0x18));
    }
    uVar9 = (uint)*(byte *)(param_1 + 0x20);
    cVar2 = *(char *)(param_1 + 0x17);
    memset(acStack_42,0,0x21);
    uVar4 = uVar9;
    if (0x1f < uVar9) {
      uVar4 = 0x1f;
    }
    memcpy(acStack_48,param_2,6);
    memcpy(acStack_42,(void *)((uint)*(byte *)(param_1 + 0x28) + *(int *)(param_1 + 0x24)),uVar4);
    uVar8 = uVar4 + 8;
    acStack_42[uVar4] = cVar1;
    acStack_42[uVar4 + 1] = cVar2;
    uVar5 = llm_adv_is_in_duplicate_scan_duplicate_exceptional_list(acStack_48,uVar8 & 0xff);
    if (uVar5 == 0) {
      if ((((*(char *)(iVar6 + 8) == '\0') || (cVar1 != '\x03')) || (acStack_42[1] != '*')) ||
         (uVar9 < 0xc)) {
        if (*(char *)(iVar6 + 9) == '\x01') {
          uVar8 = uVar4 + 2;
          pcVar7 = acStack_42;
        }
        else if (*(char *)(iVar6 + 9) == '\x02') {
          pcVar7 = acStack_48;
        }
        else {
          memcpy(acStack_50,param_2,6);
          uVar8 = 8;
          cStack_4a = cVar1;
          cStack_49 = cVar2;
        }
        llm_hash_function_blob(pcVar7,uVar8);
        uVar4 = llm_util_check_adv_report_list_by_hash();
      }
      else {
        uVar4 = llm_util_check_mesh_adv_report_list(acStack_42,uVar4);
      }
      uVar5 = (uVar4 ^ 1) & 0xff;
    }
  }
  else {
    uVar5 = 1;
  }
  return uVar5;
}

