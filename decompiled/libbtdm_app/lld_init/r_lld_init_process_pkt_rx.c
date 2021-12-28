/*
 * Last changed at upstream commit a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * https://github.com/espressif/esp32c3-bt-lib/commit/a3f7d7ffa2b261b1415042d8b7cd457cc2b4b1de
 * Upstream date: 2021-12-28 18:10:18 +0800
 * Upstream subject: Update ESP32-C3 and ESP32-S3 bt lib (33175c8)
 * Source: libbtdm_app -> lld_init.o -> r_lld_init_process_pkt_rx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_init_process_pkt_rx(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  ushort uVar7;
  
  iVar2 = lld_init_env;
  if ((lld_init_env == 0) || (iVar3 = *(int *)(param_1 * 4 + lld_init_env), iVar3 == 0)) {
                    /* WARNING: Could not recover jumptable at 0x000121a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_plf_funcs_p + 8))(0,"lld_init.c",0x360);
    return;
  }
  do {
    iVar4 = (**(code **)(_r_ip_funcs_p + 0x2a4))
                      (*(undefined1 *)(iVar3 + 0x52),*(code **)(_r_ip_funcs_p + 0x2a4));
    if (iVar4 == 0) {
      if ((*(char *)(iVar3 + 0x3d) == '\x02') ||
         ((*(char *)(iVar3 + 0x50) == '\0' && (*(char *)(iVar3 + 0x3d) == '\x01')))) {
        *(undefined1 *)(iVar3 + 0x3d) = 0;
      }
      return;
    }
    iVar4 = (uint)*(byte *)(_p_lld_env + 0xd8) * 0x14;
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    if (((*(ushort *)(iVar5 + iVar4 + 2) & 0x403d) != 0) || (*(char *)(iVar2 + 0x50) != '\0'))
    goto _L257;
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar7 = *(ushort *)(iVar5 + iVar4 + 4);
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar1 = *(undefined2 *)(iVar5 + iVar4 + 0x12);
    *(undefined1 *)(iVar3 + 0x50) = 1;
    if ((uVar7 & 0xe) == 0) {
      pcVar6 = *(code **)(_r_ip_funcs_p + 0x478);
_L272:
      (*pcVar6)(param_1,uVar1,pcVar6);
    }
    else {
      uVar7 = uVar7 & 0xf;
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      if (uVar7 == 7) {
        if ((*(ushort *)(iVar4 + 0x10 + iVar5) & 0x40) != 0) {
          pcVar6 = *(code **)(_r_ip_funcs_p + 0x47c);
          goto _L272;
        }
      }
      else if (uVar7 == 8) {
        pcVar6 = *(code **)(_r_ip_funcs_p + 0x480);
        goto _L272;
      }
    }
_L257:
    (**(code **)(_r_ip_funcs_p + 0x2a8))(*(code **)(_r_ip_funcs_p + 0x2a8));
  } while( true );
}

