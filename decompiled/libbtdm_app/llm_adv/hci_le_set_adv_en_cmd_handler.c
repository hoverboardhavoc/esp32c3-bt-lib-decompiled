/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> llm_adv.o -> hci_le_set_adv_en_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 hci_le_set_adv_en_cmd_handler(char *param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  code *pcVar7;
  byte bStack_5a;
  byte bStack_59;
  undefined4 uStack_58;
  undefined2 uStack_54;
  undefined1 auStack_52 [6];
  uint uStack_4c;
  undefined2 uStack_48;
  undefined2 uStack_46;
  undefined2 uStack_44;
  undefined2 uStack_42;
  undefined2 uStack_40;
  undefined2 uStack_3e;
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  byte bStack_3a;
  undefined1 uStack_39;
  undefined1 uStack_38;
  undefined1 uStack_37;
  undefined1 uStack_36;
  undefined1 uStack_35;
  undefined1 uStack_34;
  undefined1 uStack_33;
  undefined1 uStack_32;
  undefined1 uStack_31;
  
  if ((*(char *)(_p_llm_env + 0xd7) != '\x02') &&
     (iVar3 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0)),
     *(char *)(iVar3 + 0x25) != '\0')) {
    *(undefined1 *)(_p_llm_env + 0xd7) = 1;
    bStack_5a = (**(code **)(_r_ip_funcs_p + 0x544))(0xff,0,*(code **)(_r_ip_funcs_p + 0x544));
    if (*param_1 != '\0') {
      if (*param_1 == '\x01') {
        iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
        if ((uint)bStack_5a < (uint)*(byte *)(iVar3 + 0xd)) {
          if (*(char *)((uint)bStack_5a * 0x44 + *(int *)(_p_llm_env + 8) + 0x40) != '\x01')
          goto _L85;
        }
        else {
          iVar3 = (**(code **)(_r_ip_funcs_p + 0x4ac))(&bStack_5a,*(code **)(_r_ip_funcs_p + 0x4ac))
          ;
          if (iVar3 != 0) goto _L75;
          (**(code **)(_r_ip_funcs_p + 0x54c))(bStack_5a,*(code **)(_r_ip_funcs_p + 0x54c));
        }
        bStack_59 = 0;
        iVar2 = *(int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_5a * 0x44);
        if (((*(byte *)(iVar2 + 0xb) & 1) == 0) ||
           (iVar3 = (*(code *)*_r_modules_funcs_p)
                              (_p_llm_env + 0x12,&co_null_bdaddr,(code *)*_r_modules_funcs_p),
           iVar3 == 0)) {
          if ((*(ushort *)(iVar2 + 2) & 1) != 0) {
            iVar3 = (**(code **)(_r_ip_funcs_p + 0x4ac))
                              (&bStack_59,*(code **)(_r_ip_funcs_p + 0x4ac));
            if (iVar3 != 0) goto _L75;
            if (((*(ushort *)(iVar2 + 2) & 0xc) != 0) &&
               (iVar3 = (**(code **)(_r_ip_funcs_p + 0x4d8))
                                  (iVar2 + 0xd,*(undefined1 *)(iVar2 + 0xc),
                                   *(code **)(_r_ip_funcs_p + 0x4d8)), iVar3 != 0)) {
              iVar3 = 0xb;
              goto _L75;
            }
          }
          uStack_40 = *(undefined2 *)(iVar2 + 2);
          uStack_4c = (uint)*(byte *)(iVar2 + 9) << 0x10 | (uint)*(byte *)(iVar2 + 8) << 8 |
                      (uint)*(byte *)(iVar2 + 7);
          uStack_3b = *(undefined1 *)(iVar2 + 10);
          bStack_3a = *(byte *)(iVar2 + 0xb);
          uStack_39 = *(undefined1 *)(iVar2 + 0xc);
          bVar1 = bStack_3a & 1;
          memcpy(auStack_52,(void *)(iVar2 + 0xd),6);
          iVar3 = _p_llm_env;
          uStack_38 = *(undefined1 *)(iVar2 + 0x13);
          uStack_37 = *(undefined1 *)(iVar2 + 0x14);
          uStack_36 = *(undefined1 *)(iVar2 + 0x15);
          uStack_35 = *(undefined1 *)(iVar2 + 0x16);
          uStack_33 = *(undefined1 *)(iVar2 + 0x18);
          uStack_32 = *(undefined1 *)(iVar2 + 0x19);
          uStack_34 = uStack_36;
          if (bVar1 == 0) {
            uStack_58 = *(undefined4 *)(_p_llm_env + 0xc);
            uStack_54 = *(undefined2 *)(_p_llm_env + 0x10);
          }
          else {
            memcpy(&uStack_58,(void *)(_p_llm_env + 0x12),6);
          }
          uStack_3e = 0;
          uStack_3c = 0;
          iVar6 = *(int *)(iVar3 + 8) + (uint)bStack_5a * 0x44;
          uStack_48 = *(undefined2 *)(iVar6 + 0x28);
          uStack_44 = *(undefined2 *)(iVar6 + 0x2a);
          uStack_46 = *(undefined2 *)(iVar6 + 0x32);
          uStack_42 = *(undefined2 *)(iVar6 + 0x34);
          uStack_31 = *(undefined1 *)(iVar3 + 0xc6);
          iVar3 = (**(code **)(_r_ip_funcs_p + 0x1e4))(&uStack_58,*(code **)(_r_ip_funcs_p + 0x1e4))
          ;
          if (iVar3 != 0) goto _L75;
          iVar6 = *(int *)(_p_llm_env + 8);
          iVar3 = (uint)bStack_5a * 0x44 + iVar6;
          *(undefined1 *)(iVar3 + 0x40) = 2;
          if ((*(ushort *)(iVar2 + 2) & 1) != 0) {
            *(byte *)(iVar3 + 0x3e) = bStack_59;
            *(undefined1 *)(iVar6 + (uint)bStack_59 * 0x44 + 0x40) = 4;
          }
          if ((_bt_rf_coex_hooks_p != (int *)0x0) &&
             (pcVar7 = (code *)*_bt_rf_coex_hooks_p, pcVar7 != (code *)0x0)) {
            uVar4 = 1;
_L127:
            (*pcVar7)(0,uVar4);
          }
          goto _L83;
        }
      }
      iVar3 = 0x12;
      goto _L75;
    }
    iVar3 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    uVar5 = (uint)bStack_5a;
    if ((uVar5 < *(byte *)(iVar3 + 0xd)) &&
       (*(char *)(*(int *)(_p_llm_env + 8) + uVar5 * 0x44 + 0x40) == '\x02')) {
      iVar3 = (**(code **)(_r_ip_funcs_p + 0x1e8))(uVar5,*(code **)(_r_ip_funcs_p + 0x1e8));
      if (iVar3 != 0) goto _L75;
      *(undefined1 *)(*(int *)(_p_llm_env + 8) + (uint)bStack_5a * 0x44 + 0x40) = 3;
      if (_bt_rf_coex_hooks_p != (int *)0x0) {
        pcVar7 = (code *)*_bt_rf_coex_hooks_p;
        uVar4 = 0;
        if (pcVar7 != (code *)0x0) goto _L127;
      }
_L83:
      if (*param_1 == '\0') {
        return 0;
      }
      iVar3 = 0;
      goto _L75;
    }
    iVar3 = 0xfe;
    if ((_sdk_cfg_priv_opts & 1) != 0) goto _L75;
  }
_L85:
  iVar3 = 0xc;
_L75:
  (**(code **)(_r_ip_funcs_p + 0x4b8))(param_2,iVar3,*(code **)(_r_ip_funcs_p + 0x4b8));
  return 0;
}

