/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llm_adv.o -> hci_le_set_scan_rsp_data_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_scan_rsp_data_cmd_handler(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  void *__dest;
  int iVar4;
  int iVar5;
  code *pcVar6;
  byte abStack_21 [5];
  
  iVar4 = 0xc;
  if (*(char *)(_p_llm_env + 0xd7) != '\x02') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 1;
    iVar4 = 0x12;
    if (*param_1 < 0x20) {
      iVar4 = (**(code **)(_r_ip_funcs_p + 0x544))(0xff,0,*(code **)(_r_ip_funcs_p + 0x544));
      abStack_21[0] = (byte)iVar4;
      if (iVar4 == 0xff) {
        iVar4 = (**(code **)(_r_ip_funcs_p + 0x4ac))(abStack_21,*(code **)(_r_ip_funcs_p + 0x4ac));
        if (iVar4 != 0) goto _L59;
        (**(code **)(_r_ip_funcs_p + 0x54c))(abStack_21[0],0,*(code **)(_r_ip_funcs_p + 0x54c));
      }
      sVar2 = *(short *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44 + 0x32);
      if (*param_1 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (**(code **)(_r_ip_funcs_p + 0xd4))(*(code **)(_r_ip_funcs_p + 0xd4));
        iVar4 = 7;
        if (iVar3 == 0) goto _L59;
        bVar1 = *param_1;
        __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(7,*(code **)(_r_plf_funcs_p + 0xbc));
        memcpy(__dest,param_1 + 1,(uint)bVar1);
      }
      iVar5 = *(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44;
      *(short *)(iVar5 + 0x32) = (short)iVar3;
      iVar4 = _r_ip_funcs_p;
      *(ushort *)(iVar5 + 0x34) = (ushort)*param_1;
      if (*(char *)(iVar5 + 0x40) == '\x02') {
        pcVar6 = *(code **)(iVar4 + 0x1dc);
        (*pcVar6)(iVar3,pcVar6);
      }
      else if (sVar2 != 0) {
        pcVar6 = *(code **)(iVar4 + 0xd8);
        (*pcVar6)(sVar2,pcVar6);
      }
      iVar4 = 0;
    }
  }
_L59:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,iVar4,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

