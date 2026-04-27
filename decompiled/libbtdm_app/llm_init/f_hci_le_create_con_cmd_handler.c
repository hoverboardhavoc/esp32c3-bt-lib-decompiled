/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app -> llm_init.o -> f_hci_le_create_con_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_hci_le_create_con_cmd_handler(ushort *param_1,undefined4 param_2)

{
  byte bVar1;
  ushort uVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  byte bStack_9a;
  byte bStack_99;
  undefined1 auStack_98 [8];
  uint uStack_90;
  uint uStack_8c;
  uint uStack_88;
  uint uStack_84;
  ushort uStack_80;
  undefined2 uStack_7e;
  uint uStack_7c;
  undefined2 uStack_78;
  undefined4 uStack_70;
  undefined2 uStack_6c;
  undefined1 auStack_6a [6];
  undefined1 auStack_64 [5];
  undefined1 uStack_5f;
  undefined1 uStack_5e;
  byte bStack_5d;
  undefined1 uStack_5c;
  byte bStack_5b;
  undefined1 uStack_5a;
  ushort uStack_58;
  ushort uStack_56;
  undefined2 uStack_54;
  undefined2 uStack_52;
  ushort uStack_50;
  ushort uStack_4e;
  undefined1 uStack_34;
  
  bStack_9a = 0;
  if (*(char *)(_p_llm_env + 0xd7) != '\x02') {
    *(undefined1 *)(_p_llm_env + 0xd7) = 1;
    while( true ) {
      iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
      if (((uint)*(byte *)(iVar4 + 0xd) <= (uint)bStack_9a) ||
         (*(char *)(*(int *)(_p_llm_env + 8) + (uint)bStack_9a * 0x44 + 0x40) == '\x05')) break;
      bStack_9a = bStack_9a + 1;
    }
    iVar4 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
    if (*(byte *)(iVar4 + 0xd) <= bStack_9a) {
      if ((char)param_1[2] == '\0') {
        iVar4 = (**(code **)(_r_ip_funcs_p + 0x4d8))
                          (param_1 + 3,*(undefined1 *)((int)param_1 + 5),
                           *(code **)(_r_ip_funcs_p + 0x4d8));
        iVar6 = 0xb;
        if (iVar4 != 0) goto _L42;
      }
      bStack_99 = *(byte *)((int)param_1 + 5);
      memcpy(auStack_98,param_1 + 3,6);
      if (*(char *)(_p_llm_env + 0xc6) != '\0') {
        lld_peer_rpa_to_id(auStack_98,&bStack_99);
      }
      if (param_1[1] <= *param_1) {
        uVar7 = (uint)param_1[8];
        if (((((((param_1[7] <= uVar7) && ((ushort)(param_1[1] - 4) < 0x3ffd)) &&
               ((ushort)(*param_1 - 4) < 0x3ffd)) &&
              ((param_1[0xb] <= param_1[0xc] && ((uint)_g_ble_con_interval_min <= (uint)param_1[7]))
              )) && ((uVar7 < 0xc81 && (((param_1[10] - 10 & 0xffff) < 0xc77 && (param_1[9] < 500)))
                     ))) && (bStack_99 < 4)) &&
           ((((byte)param_1[6] < 4 && ((ushort)(param_1[9] + 1) * uVar7 < (uint)param_1[10] << 2))
            && ((((byte)param_1[6] & 1) == 0 ||
                (iVar4 = (*(code *)*_r_modules_funcs_p)
                                   (_p_llm_env + 0x12,&co_null_bdaddr,(code *)*_r_modules_funcs_p),
                iVar4 == 0)))))) {
          iVar6 = (**(code **)(_r_ip_funcs_p + 0x4ac))(&bStack_9a,*(code **)(_r_ip_funcs_p + 0x4ac))
          ;
          if (iVar6 != 0) goto _L42;
          uStack_90 = (uint)param_1[7] << 1;
          uStack_8c = (uint)param_1[8] << 1;
          uVar7 = (uint)param_1[0xb];
          if (uStack_90 < param_1[0xb]) {
            uVar7 = uStack_90;
          }
          if (uVar7 < 5) {
            uVar7 = 5;
          }
          uVar9 = (uint)param_1[0xc];
          if (uStack_8c < param_1[0xc]) {
            uVar9 = uStack_8c;
          }
          if (uVar9 < 5) {
            uVar9 = 5;
          }
          uStack_80 = (ushort)bStack_9a;
          uStack_7e = 0;
          uStack_88 = uVar7;
          uStack_84 = uVar9;
          iVar4 = (**(code **)(_r_ip_funcs_p + 0x6f8))
                            (&uStack_90,0,*(code **)(_r_ip_funcs_p + 0x6f8));
          iVar6 = 0xd;
          if (iVar4 != 0) goto _L42;
          if (*(int *)(*(int *)(_p_llm_env + 8) + (uint)bStack_9a * 0x44) != 0) {
            (**(code **)(_r_plf_funcs_p + 8))(0x10000,0xda,*(code **)(_r_plf_funcs_p + 8));
          }
          uVar8 = (uint)bStack_9a;
          iVar4 = *(int *)(_p_llm_env + 8);
          uVar5 = (*(code *)_r_modules_funcs_p[0x32])(0,0,0,0x3a,(code *)_r_modules_funcs_p[0x32]);
          *(undefined4 *)(iVar4 + uVar8 * 0x44) = uVar5;
          iVar4 = _p_llm_env;
          iVar6 = *(int *)(_p_llm_env + 8);
          puVar3 = *(undefined1 **)((uint)bStack_9a * 0x44 + iVar6);
          if (puVar3 != (undefined1 *)0x0) {
            puVar3[9] = 1;
            *(ushort *)(puVar3 + 10) = *param_1;
            *(ushort *)(puVar3 + 0xc) = param_1[1];
            *puVar3 = (char)param_1[2];
            bVar1 = (byte)param_1[6];
            puVar3[1] = bVar1;
            puVar3[2] = bStack_99;
            memcpy(puVar3 + 3,auStack_98,6);
            *(ushort *)(puVar3 + 0xe) = param_1[7];
            *(ushort *)(puVar3 + 0x10) = param_1[8];
            *(ushort *)(puVar3 + 0x12) = param_1[9];
            uVar2 = param_1[10];
            *(short *)(puVar3 + 0x16) = (short)uVar7;
            *(short *)(puVar3 + 0x18) = (short)uVar9;
            *(ushort *)(puVar3 + 0x14) = uVar2;
            if (bVar1 == 2) {
_L37:
              iVar6 = (uint)bStack_9a * 0x44 + iVar6;
              *(undefined4 *)(iVar6 + 4) = *(undefined4 *)(iVar4 + 0xc);
              *(undefined2 *)(iVar6 + 8) = *(undefined2 *)(iVar4 + 0x10);
            }
            else {
              if (bVar1 < 3) {
                if (bVar1 == 0) goto _L37;
              }
              else if (bVar1 != 3) {
                (**(code **)(_r_plf_funcs_p + 0xc))
                          (bVar1,0,0x10000,0x104,*(code **)(_r_plf_funcs_p + 0xc));
                goto _L36;
              }
              memcpy((void *)(iVar6 + (uint)bStack_9a * 0x44 + 4),(void *)(iVar4 + 0x12),6);
            }
          }
_L36:
          bVar1 = bStack_9a;
          iVar4 = _p_llm_env;
          uVar7 = (uint)bStack_9a;
          iVar6 = uVar7 * 0x44;
          *(undefined1 *)(*(int *)(_p_llm_env + 8) + iVar6 + 0x40) = 5;
          memcpy(auStack_6a,auStack_98,6);
          memcpy(auStack_64,(void *)(iVar4 + 0x1d),5);
          uStack_5e = 1;
          uStack_58 = *param_1;
          bStack_5d = bVar1;
          uStack_56 = param_1[1];
          uStack_54 = (undefined2)(uStack_7c >> 1);
          uStack_52 = uStack_78;
          uStack_50 = param_1[9];
          uStack_4e = param_1[10];
          uStack_5c = (undefined1)param_1[6];
          bStack_5b = bStack_99;
          uStack_5a = (undefined1)param_1[2];
          iVar6 = *(int *)(iVar4 + 8) + iVar6;
          uStack_70 = *(undefined4 *)(iVar6 + 4);
          uStack_6c = *(undefined2 *)(iVar6 + 8);
          uStack_5f = 0;
          uStack_34 = *(undefined1 *)(iVar4 + 0xc6);
          if ((_bt_rf_coex_hooks_p != (undefined4 *)0x0) &&
             ((code *)*_bt_rf_coex_hooks_p != (code *)0x0)) {
            (*(code *)*_bt_rf_coex_hooks_p)(uVar7,1,1);
          }
          iVar6 = (**(code **)(_r_ip_funcs_p + 0x494))(&uStack_70,*(code **)(_r_ip_funcs_p + 0x494))
          ;
          if (iVar6 != 0) {
            iVar6 = 3;
          }
          goto _L42;
        }
      }
      iVar6 = 0x12;
      goto _L42;
    }
  }
  iVar6 = 0xc;
_L42:
  (**(code **)(_r_ip_funcs_p + 0x4bc))(param_2,iVar6,*(code **)(_r_ip_funcs_p + 0x4bc));
  return 0;
}

