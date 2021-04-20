/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
 * Source: libbtdm_app -> llm_adv.o -> hci_le_set_adv_data_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_adv_data_cmd_handler(byte *param_1,undefined4 param_2)

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
        if (iVar4 != 0) goto _L41;
        (**(code **)(_r_ip_funcs_p + 0x54c))(abStack_21[0],0,*(code **)(_r_ip_funcs_p + 0x54c));
      }
      sVar2 = *(short *)(*(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44 + 0x28);
      if (*param_1 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (**(code **)(_r_ip_funcs_p + 0xd4))(*(code **)(_r_ip_funcs_p + 0xd4));
        iVar4 = 7;
        if (iVar3 == 0) goto _L41;
        bVar1 = *param_1;
        __dest = (void *)(**(code **)(_r_plf_funcs_p + 0xbc))(7,*(code **)(_r_plf_funcs_p + 0xbc));
        memcpy(__dest,param_1 + 1,(uint)bVar1);
      }
      iVar5 = *(int *)(_p_llm_env + 8) + (uint)abStack_21[0] * 0x44;
      *(short *)(iVar5 + 0x28) = (short)iVar3;
      iVar4 = _r_ip_funcs_p;
      *(ushort *)(iVar5 + 0x2a) = (ushort)*param_1;
      if (*(char *)(iVar5 + 0x40) == '\x02') {
        pcVar6 = *(code **)(iVar4 + 0x180);
        (*pcVar6)(iVar3,pcVar6);
      }
      else if (sVar2 != 0) {
        pcVar6 = *(code **)(iVar4 + 0xd8);
        (*pcVar6)(sVar2,pcVar6);
      }
      iVar4 = 0;
    }
  }
_L41:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,iVar4,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

