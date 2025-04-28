/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_scan.o -> r_llm_le_adv_report_ind_duplicate_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint r_llm_le_adv_report_ind_duplicate_check(int param_1,void *param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  byte abStack_118 [6];
  byte bStack_112;
  byte bStack_111;
  byte abStack_110 [6];
  byte abStack_10a [234];
  
  if ((*(char *)(_p_llm_env + 0xd7) == '\x01') || ((*(byte *)(_p_llm_env + 0xd4) & 0x40) != 0)) {
    iVar5 = r_llm_le_scan_duplicate_opt_get();
    bVar1 = *(byte *)(param_1 + 0x15);
    if ((*(byte *)(_p_llm_env + 0xd4) & 1) != 0) {
      if (*(char *)(iVar5 + 0x24) != '\0') {
        llm_util_flush_list();
        (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
        iVar3 = _r_osi_funcs_p;
        *(undefined1 *)(iVar5 + 0x24) = 0;
        (**(code **)(iVar3 + 0x18))(*(code **)(iVar3 + 0x18));
      }
      if ((*(char *)(iVar5 + 0x25) != '\0') && (*(char *)(iVar5 + 8) != '\0')) {
        llm_util_flush_list(iVar5 + 0x10);
        (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
        iVar3 = _r_osi_funcs_p;
        *(undefined1 *)(iVar5 + 0x25) = 0;
        (**(code **)(iVar3 + 0x18))(*(code **)(iVar3 + 0x18));
      }
      uVar9 = (uint)*(byte *)(param_1 + 0x20);
      bVar2 = *(byte *)(param_1 + 0x17);
      abStack_110[0] = 0;
      abStack_110[1] = 0;
      abStack_110[2] = 0;
      abStack_110[3] = 0;
      memset(abStack_110 + 4,0,0xe9);
      uVar4 = uVar9;
      if (0xe5 < uVar9) {
        uVar4 = 0xe5;
      }
      memcpy(abStack_110,param_2,6);
      memcpy(abStack_10a,(void *)((uint)*(byte *)(param_1 + 0x28) + *(int *)(param_1 + 0x24)),uVar4)
      ;
      uVar8 = uVar4 + 8;
      abStack_10a[uVar4] = bVar1;
      abStack_10a[uVar4 + 1] = bVar2;
      uVar6 = llm_adv_is_in_duplicate_scan_duplicate_exceptional_list(abStack_110,uVar8 & 0xff);
      if (uVar6 != 0) {
        return uVar6;
      }
      if ((((*(char *)(iVar5 + 8) == '\0') || ((bVar1 & 0xef) != 0)) || (abStack_10a[1] != '*')) ||
         (uVar9 < 0xc)) {
        if (*(char *)(iVar5 + 9) == '\x01') {
          uVar8 = uVar4 + 2;
          pbVar7 = abStack_10a;
        }
        else if (*(char *)(iVar5 + 9) == '\x02') {
          pbVar7 = abStack_110;
        }
        else {
          memcpy(abStack_118,param_2,6);
          uVar8 = 8;
          pbVar7 = abStack_118;
          bStack_112 = bVar1;
          bStack_111 = bVar2;
        }
        llm_hash_function_blob(pbVar7,uVar8);
        uVar4 = llm_util_check_adv_report_list_by_hash();
      }
      else {
        uVar4 = llm_util_check_mesh_adv_report_list(abStack_10a,uVar4);
      }
      return (uVar4 ^ 1) & 0xff;
    }
  }
  return 1;
}

