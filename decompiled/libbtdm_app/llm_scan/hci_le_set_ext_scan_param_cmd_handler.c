/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> llm_scan.o -> hci_le_set_ext_scan_param_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_ext_scan_param_cmd_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  byte bStack_21;
  
  if (*(char *)(_p_llm_env + 0xd7) == '\x01') {
_L46:
    iVar3 = 0xc;
  }
  else {
    *(undefined1 *)(_p_llm_env + 0xd7) = 2;
    bStack_21 = 0;
    while( true ) {
      iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      if ((uint)*(byte *)(iVar3 + 0xd) <= (uint)bStack_21) break;
      if ((byte)(*(char *)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44 + 0x40) - 6U) < 3)
      break;
      bStack_21 = bStack_21 + 1;
    }
    iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if ((uint)bStack_21 < (uint)*(byte *)(iVar3 + 0xd)) {
      if (*(char *)((uint)bStack_21 * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) != '\x06') goto _L46;
    }
    else {
      iVar3 = (**(code **)(_r_ip_funcs_p + 0x4ac))(&bStack_21,*(code **)(_r_ip_funcs_p + 0x4ac));
      if (iVar3 != 0) goto _L53;
    }
    bVar1 = param_1[2];
    if ((bVar1 == 1) || (bVar1 == 4)) {
      uVar5 = 1;
    }
    else {
      iVar3 = 0x12;
      uVar5 = 2;
      if (bVar1 != 5) goto _L53;
    }
    pbVar6 = param_1 + 4;
    iVar3 = 0;
    do {
      if ((((*(ushort *)(pbVar6 + 2) < *(ushort *)(pbVar6 + 4)) || (1 < *pbVar6)) ||
          (*(ushort *)(pbVar6 + 4) < 4)) || (*(ushort *)(pbVar6 + 2) < 4)) goto _L68;
      uVar4 = iVar3 + 1;
      pbVar6 = pbVar6 + 6;
      iVar3 = 1;
    } while (uVar4 < uVar5);
    if ((*param_1 < 4) && (param_1[1] < 4)) {
      iVar3 = *(int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44);
      if (iVar3 != 0) {
        (**(code **)(_r_modules_funcs_p + 0xd8))(iVar3 + -0xc,*(code **)(_r_modules_funcs_p + 0xd8))
        ;
        *(undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44) = 0;
      }
      iVar3 = 0;
      uVar2 = 1;
      puVar7 = (undefined4 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_21 * 0x44);
      *puVar7 = param_1;
      *(undefined1 *)(puVar7 + 0x10) = 6;
      goto _L58;
    }
_L68:
    iVar3 = 0x12;
  }
_L53:
  uVar2 = 0;
_L58:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,iVar3,*(code **)(_r_ip_funcs_p + 0x4b8));
  return uVar2;
}

